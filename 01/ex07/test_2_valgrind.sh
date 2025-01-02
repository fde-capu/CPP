#!/bin/sh

echo "This is a file for testing single character replacement.\nA--\n-A-\n--A\nA\nA" >> test_2.txt

valgrind ./replace test_2.txt A X
cat ./test_2.txt.replace
rm -f test_2.txt.replace
valgrind ./replace "test_2.txt" A X 
cat ./test_2.txt.replace
rm -f test_2.txt.replace
valgrind ./replace test_2.txt "A" X 
cat ./test_2.txt.replace
rm -f test_2.txt.replace
valgrind ./replace test_2.txt A "X"
cat ./test_2.txt.replace
rm -f test_2.txt.replace

rm -f test_2.txt
