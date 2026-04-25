#!/bin/bash

#This script compares real malloc with my malloc in terms of speed

NAME="libft_malloc.so"
LIBFT="libft.a"

cleanup()
{
	rm -f custom real libft.a libft_malloc.so null
}

error()
{
	echo "something went wrong!"
	echo "detail: $1"
	cleanup
	exit 1
}

# 1)    compilation
cp > /dev/null ../$NAME ../build/$LIBFT . || \
(echo compiling... ; cd ../ && make > /dev/null && cp build/libft.a libft_malloc.so test/ || error "Libft compilation")

# 2)	populating array of directories
dirs=($(ls . | grep *test))

# 3)	do tests
N=0
div="\033[31m+------------------------+\033[0m"

for dir in "${dirs[@]}"
do
	echo -e "$div\n" "\033[33mtest number \033[0m$N" ":\n" $(cat "$dir/info") "\n$div"
	cc -Wall -Wextra -Werror -g "$dir"/real.c $LIBFT -o real > /dev/null || error "compiling real for $dir"
	cc -Wall -Wextra -Werror -g "$dir"/custom.c  -L. -lft_malloc -Wl,-rpath,. -o custom > /dev/null || error "compiling custom for $dir"
	echo -e "\033[33mCUSTOM MALLOC\033[0m:"
	time ./custom
	echo -e "\033[33mREAL MALLOC\033[0m:"
	time ./real
	((N++))
done

# 4)	cleanup
cleanup