#!/bin/bash

cmake --build build -t {{projectName}}
if [ $? -eq 0 ]; then
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/{{projectName}}/" ]]; then
        cd {{projectName}}
    fi
    echo
    ../build/{{projectFile}} "${@:1}" 2>&1
fi
