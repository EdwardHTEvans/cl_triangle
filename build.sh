#!/bin/bash
cd "$(dirname "$0")"
cmake -S . -B ./build
cd ./build
make
