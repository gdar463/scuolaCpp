#!/bin/bash

cmake --build build -t Pointers_09-23
if [ $? -eq 0 ]; then
    mv build/Pointers_09-23 build/pointers_09-23
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/Pointers_09-23/" ]]; then
        cd Pointers_09-23
    fi
    echo
    ../build/pointers_09-23 "${@:1}" 2>&1
fi

