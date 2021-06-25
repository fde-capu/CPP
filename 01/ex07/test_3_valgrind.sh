#!/bin/sh

echo "This is a file for testing different lenghts replacement (a < b)\nA--\n-A-\n--A\nA\nA" >> test_3.txt

valgrind ./replace test_3.txt A XYZ
cat ./test_3.txt.replace
rm -f test_3.txt.replace
valgrind ./replace "test_3.txt" A XYZ
cat ./test_3.txt.replace
rm -f test_3.txt.replace
valgrind ./replace test_3.txt "A" XYZ
cat ./test_3.txt.replace
rm -f test_3.txt.replace
valgrind ./replace test_3.txt A "XYZ"
cat ./test_3.txt.replace
rm -f test_3.txt.replace

rm -f test_3.txt

echo "This is a file for testing different lenghts replacement (a > b)\nAAA--\n-AAA-\n--AAA\nAAA\nAAA" >> test_3.txt

valgrind ./replace test_3.txt AAA X
cat ./test_3.txt.replace
rm -f test_3.txt.replace
valgrind ./replace "test_3.txt" AAA X
cat ./test_3.txt.replace
rm -f test_3.txt.replace
valgrind ./replace test_3.txt "AAA" X
cat ./test_3.txt.replace
rm -f test_3.txt.replace
valgrind ./replace test_3.txt AAA "X"
cat ./test_3.txt.replace
rm -f test_3.txt.replace

rm -f test_3.txt
