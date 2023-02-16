#!/bin/sh
rm ./test/TestCases/$1.out
gcc -I./inc -I./src -o./test/TestCases/$1.out ./test/TestCases/$1.c
./test/TestCases/$1.out
