#!/bin/sh
file="code.cpp"
objfile="code.exe"

g++ -std=gnu++1y -O2  -o $objfile $file
./$objfile < input