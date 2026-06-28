#!/bin/bash

set -e

mkdir -p bin

g++ -O3 -s -fvisibility=hidden -shared -fPIC -Wall -Wextra -I./include src/api.cpp src/parser.cpp src/crypto.cpp -o bin/libjdat.so