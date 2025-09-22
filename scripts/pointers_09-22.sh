#!/bin/bash

cmake --build build -t Pointers_09-22
if [ $? -eq 0 ]; then
    mv build/Pointers_09-22 build/pointers_09-22
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/Pointers_09-22/" ]]; then
        cd Pointers_09-22
    fi
    echo
    ../build/pointers_09-22 "${@:1}" 2>&1
fi

