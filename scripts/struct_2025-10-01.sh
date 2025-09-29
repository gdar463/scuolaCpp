#!/bin/bash

cmake --build build -t Struct_2025-10-01
if [ $? -eq 0 ]; then
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/Struct_2025-10-01/" ]]; then
        cd Struct_2025-10-01
    fi
    echo
    ../build/struct_2025-10-01 "${@:1}" 2>&1
fi
