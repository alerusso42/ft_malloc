#!/bin/bash

cleanup()
{
	rm -f custom real libft.a
}

error()
{
	echo "something went wrong!"
	echo "detail: $1"
	cleanup
	exit 1
}

# 1)    compilation
(cd ../ && make libft > /dev/null && mv libft.a test/ || error "compilation")

# 2)	populating array of directories
dirs=($(ls . | grep *test))

# 3)	aggregating malloc srcs

src_malloc=$(ls ../srcs/functions/*.c ../srcs/utils/*.c)

# 4)	do tests
N=0
div="\033[31m+------------------------+\033[0m"

for dir in "${dirs[@]}"
do
	echo -e "$div\n" "\033[33mtest number \033[0m$N" ":\n" $(cat "$dir/info") "\n$div"
	cc -Wall -Wextra -Werror -g "$dir"/real.c $src_malloc libft.a -o real > /dev/null || error "compiling real for $dir"
	cc -Wall -Wextra -Werror "$dir"/custom.c $src_malloc libft.a -o custom > /dev/null || error "compiling custom for $dir"
	echo -e "\033[33mCUSTOM MALLOC\033[0m:"
	time ./custom
	echo -e "\033[33mREAL MALLOC\033[0m:"
	time ./real
	((N++))
done

# 5)	cleanup
cleanup