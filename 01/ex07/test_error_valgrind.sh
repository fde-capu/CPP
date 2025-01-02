#!/bin/sh

valgrind ./replace								# No arguments.
echo "A Error: $?";

valgrind ./replace ./test_error.txt this that	# File does not exist.
echo "B Error: $?";

echo "TEST_FILE" >> ./test_error.txt
valgrind ./replace ./test_error.txt "FILE"		# Lack of argument count.
echo "C Error: $?";

valgrind ./replace ./test_error.txt "" that		# Null string as first.
echo "D Error: $?";

valgrind ./replace ./test_error.txt this ""		# Null string as second.
echo "E Error: $?";

echo "EXISTING_FILE" >> ./test_error.txt.replace
valgrind ./replace ./test_error.txt this that	# Will not override if file .replace exists.
echo "F Error: $?";

rm -f ./test_error.txt.replace
rm -f test_error.txt
