#!/bin/bash

cmake --build build -t Pointers
if [ $? -eq 0 ]; then
    mv build/Pointers build/pointers
    if [[ "${PWD}" != "/home/dario/projects/cpp/scuola/Pointers" ]]; then
        cd Pointers
    fi
    echo
    ../build/pointers "${@:1}" 2>&1
fi

