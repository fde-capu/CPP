#!/bin/sh

#
# 42 CPP Module 06 ex00 Test
# fde-capu, 202107
#

BIN=convert;
set -f ;
test()
{
	set +f ;
	ARG=$1 ;
	echo "\n./$BIN $1";
	./$BIN $1 ;
	set -f ;
}
test 0 ;
test 0.0f ;
test 0.0 ;
test -0 ;
test -0.0f ;
test -0.0 ;
test nanf ;
test +inff ;
test -inff ;
test nan ;
test +inf ;
test -inf ;
test 42 ;
test 42.0f ;
test 42.0 ;
test 42.4f ;
test 42.4 ;
test -42 ;
test -42.0f ;
test -42.0 ;
test -42.4f ;
test -42.4 ;
test  42.42 ; # header.h: #define PRECISION 1
test -42.000f ;
test * ; # thanks to `set -f` (disable filename expansion)
test 'X' ;
test X ;
test "X" ;
test '42' ;
test "42.0f" ;
test '42.42' ;
test "\" \"" ;
test "' '" ;
test "' ' 'X'" ;
test "' ' 'X' T" ;
test ;
test 'string' ;
test string ;
test "\"string\"" ;
test -X ;
test '-' ;
test '+' ;
test "5x";
test --7 ;
test +11 ;
test ++11 ;
test +42.11 ;
test 99999999999999999 ;
test 9999999.9999999999 ;
test 9999999999999999.9999999999 ;
test 999999999999999999999999999.9999999999 ;
test 9999999999999999999999999999999999999999999.9999999999 ;
test -9999999999999999999999999999999999999999999.9999999999 ;
test 999999999999999999999999999999999999999999999999999999999999999999999999.9999999999 ;
#echo done.
