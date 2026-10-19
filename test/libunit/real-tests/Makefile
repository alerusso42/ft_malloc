SRC = main.c\
	$(addprefix malloc_stressTest/, $(shell ls malloc_stressTest | grep '\.c' | grep -v __template.cc))\
	$(addprefix calloc_stressTest/, $(shell ls calloc_stressTest | grep '\.c' | grep -v __template.cc))\
	$(addprefix calloc/, $(shell ls calloc | grep '\.c' | grep -v __template.cc))\
	$(addprefix malloc/, $(shell ls malloc | grep '\.c' | grep -v __template.cc))\
	$(addprefix realloc_stressTest/, $(shell ls realloc_stressTest | grep '\.c' | grep -v __template.cc))\
	$(addprefix realloc/, $(shell ls realloc | grep '\.c' | grep -v __template.cc))
NAME = test.out
LIBUNIT = ../libunit.a
PROJ_OBJ = ../
OBJ = $(SRC:.c=.o)
COMP = gcc -g -Wall -Werror -Wextra

all: $(NAME)
	
$(NAME) : $(LIBUNIT) $(OBJ) 
	echo $(SRC)
	$(COMP) $(OBJ) $(LIBUNIT) ../../../libft_malloc.so -o $(NAME)

$(LIBUNIT):
	$(MAKE) -C ../

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ) $(OBJ_BONUS) *.out

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --child-silent-after-fork=yes --trace-children=no --track-fds=yes  -s ./$(NAME)

.PHONY: all clean fclean re test
.SILENT:
