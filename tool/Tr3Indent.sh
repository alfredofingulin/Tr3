#!/bin/sh
indent -bap -bli0 -i4 -l80 -ncs -npcs -npsl -fca -lc160 -fc1 -ts4 -nut $1
mv $1~ $1_old
