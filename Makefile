# the name of the library is libft_malloc + architecture name
# if it's empty, it is obtained using shell commands

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

BUILD := build
NAME := $(BUILD)/libft_malloc_$(HOSTTYPE).so
LINK_NAME := libft_malloc.so
FILE := test_file
LIBFT := $(BUILD)/libft.a

SRC := $(shell ls ./srcs/functions/*.c ./srcs/utils/*.c)
OBJ := $(patsubst %.c, $(BUILD)/%.o, $(SRC))

# "-Wl," tells the compiler to give the next flag to the linker 
# whole archive specify that all the .a must be put into the .so
# otherwise only used functions in .so will be inserted
# it's important to close with --no-whole-archive: compiler appends libc so
# without this, all the entire libc would be put into libft.malloc.so

$(NAME): $(OBJ) $(LIBFT)
	cc -Wall -Wextra -Werror -shared -g \
        $(OBJ) \
        -Wl,--whole-archive $(LIBFT) -Wl,--no-whole-archive \
        -o $(NAME)
	ln -sf $(NAME) $(LINK_NAME)

$(BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	cc -Wall -Wextra -Werror -fPIC -g -c $< -o $@

$(LIBFT): 
	make libft

all: $(NAME)
	
clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf a.out libft.a libft_malloc.so build/*

re: fclean $(NAME)


libft:
	(cd Libft/ && make all && cp libft.a $$OLDPWD/build && make fclean)