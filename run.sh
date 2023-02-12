#!/bin/bash

# build
make clean all target=${1}

# execute
./test/${1}.out
