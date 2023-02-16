#!/bin/sh
rm -v *.*~
rm -v *.o
rm -v *.map
rm -v ./doc/*.*~
rm -v ./src/*.*~
rm -v ./inc/*.*~
# rm -v ./ext/\todo board/*.*~
rm -v ./ext/simulator/*.*~
rm -v ./test/TestCases/*.*~
rm -v ./test/examples/*.*~
# rm -v ./test/\todo trtgen/*.*~
rm -v ./tool/*.*~
rm -v ./doc/*.bak
rm -v ./src/*.bak
rm -v ./inc/*.bak
# rm -v ./ext/\todo board/*.bak
rm -v ./ext/simulator/*.bak
rm -v ./test/TestCases/*.bak
rm -v ./test/examples/*.bak
# rm -v ./test/\todo trtgen/*.bak
rm -v ./tool/*.bak
rm -v ./test/TestCases/*.out
rm -v Tr3DoxygenErrors.err
