#!/bin/bash

cmake --build build -t Pointers_09-16
if [ $? -eq 0 ]; then
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/Pointers_09-16/" ]]; then
        cd Pointers_09-16
    fi
    echo
    ../build/pointers_09-16 "${@:1}" 2>&1
fi

