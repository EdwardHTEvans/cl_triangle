#!/bin/bash
cd "$(dirname "$0")"
cmake -S . -B ./out/build
cd ./out/build
make
