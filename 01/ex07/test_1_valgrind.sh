#!/bin/sh

echo "This is a file for testing. '42' must appear somewhere below.\nAA bb CC" >> test_1.txt

valgrind ./replace test_1.txt AA 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace "test_1.txt" AA 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace test_1.txt "AA" 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace test_1.txt AA "42"
cat ./test_1.txt.replace
rm -f test_1.txt.replace

valgrind ./replace test_1.txt bb 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace "test_1.txt" bb 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace test_1.txt "bb" 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace test_1.txt bb "42"
cat ./test_1.txt.replace
rm -f test_1.txt.replace

valgrind ./replace test_1.txt CC 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace "test_1.txt" CC 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace test_1.txt "CC" 42
cat ./test_1.txt.replace
rm -f test_1.txt.replace
valgrind ./replace test_1.txt CC "42"
cat ./test_1.txt.replace
rm -f test_1.txt.replace

rm -f test_1.txt
