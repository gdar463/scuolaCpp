#!/bin/bash

cmake --build build -t Struct_2025-09-29
if [ $? -eq 0 ]; then
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/Struct_2025-09-29/" ]]; then
        cd Struct_2025-09-29
    fi
    echo
    ../build/struct_2025-09-29 "${@:1}" 2>&1
fi
