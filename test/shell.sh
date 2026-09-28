#!/bin/bash

# this test creates a new shell that uses my malloc implementation
# ⚠️ currently this test does not work (debug state)

NAME="libft_malloc.so"
LIBFT="libft.a"

cleanup()
{
	rm -f libft_malloc.so
	rm -rf ../build
}

error()
{
	echo "something went wrong!"
	echo "detail: $1"
	cleanup
	exit 1
}

# 1)    compilation
(cd ../ && make > /dev/null)
cp > /dev/null ../$NAME ../build/$LIBFT . || \
(echo compiling... ; make > /dev/null && cp build/libft.a libft_malloc.so test/ || error "Libft compilation")

export LD_DEBUG=libs LD_PRELOAD="$PWD/$NAME"
bash
#cleanup