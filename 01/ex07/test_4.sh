#!/bin/sh

echo "This is a file for testing contained substitutions (string to XX_string_XX)\nABC--\n-ABC-\n--ABC\nABC\nABC" >> test_4.txt

./replace test_4.txt ABC XX_ABC_XX
cat ./test_4.txt.replace
rm -f test_4.txt.replace
./replace "test_4.txt" ABC XX_ABC_XX
cat ./test_4.txt.replace
rm -f test_4.txt.replace
./replace test_4.txt "ABC" XX_ABC_XX
cat ./test_4.txt.replace
rm -f test_4.txt.replace
./replace test_4.txt ABC "XX_ABC_XX"
cat ./test_4.txt.replace
rm -f test_4.txt.replace

rm -f test_4.txt
