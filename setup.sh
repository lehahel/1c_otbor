#!/bin/sh

rm -rf bin build
mkdir build
cd build
echo "\033[0;32m=====\033[0m          Building project...          \033[0;32m=====\033[0m"
cmake .. > /dev/null
make     > /dev/null
pip install pypng > /dev/null
echo "\033[0;32m=====\033[0m  The project was successfully built!  \033[0;32m=====\033[0m"
cd ..   

