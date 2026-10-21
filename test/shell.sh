#!/bin/bash

# this test creates a new shell that uses my malloc implementation
# ⚠️ currently this test does not work (debug state)

NAME="$PWD/../libft_malloc.so"
LIBFT="libft.a"
DEBUG=""

# set -x

error()
{
	echo "something went wrong!"
	echo "detail: $1"
	cleanup
	exit 1
}

usage()
{
	echo "Description: run the malloc shared library in bash"
	echo "Flags:"
	echo "--debug ==>	prints info about what the shell is doing (LD_DEBUG=libs)"
	echo "--help ==>	prints this message and exit with code 0"
	exit 0
}

parse_flags()
{
	for x in "$@"; do
		test "$x" == "--debug" && DEBUG="LD_DEBUG=libs"
		test "$x" == "--help" && usage
	done
}

# 1)    compilation
(cd ../ && make > /dev/null) || error "Compilation error"
# 2)	parse flags and export library

parse_flags "$@"
export LD_PRELOAD="$NAME"
test "$DEBUG" != "" && export LD_DEBUG=libs

# 3)	run bash
bash
#cleanup