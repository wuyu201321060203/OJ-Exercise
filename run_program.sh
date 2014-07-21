#!/bin/sh
clang++ -g -o $1 $1".cc" -std=c++11 -Wall -lpthread