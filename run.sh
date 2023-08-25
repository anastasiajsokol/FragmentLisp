#!/bin/sh

set -e

g++ -std=c++17 main.cpp lexer/*.cpp -o fragment

set +e

./fragment
result=$?
rm fragment
exit $result