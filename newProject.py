#!/usr/bin/env python3
import argparse
from datetime import date
import os
import sys

def replace_by_dir(input: str, replacement_patterns: dict[str, str]):
    for pattern, replace in replacement_patterns.items():
        input = input.replace(pattern,replace)
    return input

parser = argparse.ArgumentParser("Scuola CPP Setup", description="Creates folders and CMake files for new projects")
parser.add_argument("topic", help="Topic of the project")
parser.add_argument("date", help="Date of the project (format: YYYY-MM-DD)")
parser.add_argument("--dry-run", help="Don't write files", action="store_true")
if len(sys.argv)==1: 
    parser.print_help(sys.stderr)
    sys.exit()

args = parser.parse_args()
dry_run: bool = args.dry_run if vars(args)["dry_run"] is not None else False

projectTopic: str = args.topic
projectDate: str = date.fromisoformat(args.date).strftime("_%Y-%m-%d")
project = projectTopic + projectDate
projectLower = project.lower()

bashFileReplacements = {
    "{{projectName}}": project,
    "{{projectFile}}": projectLower
}
with open("example/example.sh", "rt") as f:
    bashFile = f.read()
bashFile = replace_by_dir(bashFile, bashFileReplacements)

cppFileReplacements = {
    "{{projectName}}": project
}
with open("example/example.cpp", "rt") as f:
    cppFile = f.read()
cppFile = replace_by_dir(cppFile, cppFileReplacements)

if not dry_run:
    with open("scripts/" + projectLower + ".sh", "wt") as f:
        f.write(bashFile)
    if sys.platform == "linux":
        os.system("chmod +x ./scripts/" + projectLower + ".sh")

    with open("CMakeLists.txt", "rt+") as f:
        cmake = f.readlines()
        fileLine = 0
        length = len(cmake)
        for i in range(length):
            if cmake[length - 1 - i].startswith("file("):
                fileLine = length - i
                break
        cmake.insert(fileLine, "file(GLOB " + project + "_SRC CONFIGURE_DEPENDS \"" + project + "/*.hpp\" \"" + project + "/*.cpp\")\n")
        cmake.append("add_executable(" + project + " ${" + project + "_SRC})\n")
        f.seek(0)
        f.writelines(cmake)
        f.truncate()
    
    os.makedirs(project)
    with open(project + "/main.cpp", "wt") as f:
        f.write(cppFile)
else:
    print("-- Bash File: \"scripts/" + project + ".sh\"\n")
    print("```")
    print(bashFile, end="")
    print("```\n")

    with open("CMakeLists.txt", "rt") as f:
        cmake = f.readlines()
        fileLine = 0
        length = len(cmake)
        for i in range(length):
            if cmake[length - 1 - i].startswith("file("):
                fileLine = length - i
                break
        cmake.insert(fileLine, "file(GLOB " + project + "_SRC CONFIGURE_DEPENDS \"" + project + "/*.hpp\" \"" + project + "/*.cpp\")\n")
        cmake.append("add_executable(" + project + " ${" + project + "_SRC})\n")

    print("-- CMake File:\n")
    print("```")
    print("".join(cmake), end="")
    print("```\n")

    print("-- CPP File: \"" + project + "/main.cpp\"\n")
    print("```")
    print(cppFile, end="")
    print("```\n")

print("Done!")
