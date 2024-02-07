NAME = push_swap
B_NAME = checker

SRC = sources/ft_printf.c\
	sources/sources1.c\
	sources/sources2.c\
	sources/ft_split.c\
	operations_a.c\
	operations_b.c\
	checker_src.c\
	quicksort.c\
	source1.c\
	sort_3.c

OBJ = $(SRC:.c=.o)

B_SRC = push_swap.c

B_OBJ = $(B_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) 
	$(CC) $(CFLAGS) $(NAME) push_swap.c -o $(NAME)

bonus:	$(OBJ) $(B_OBJ)
	ar rc $(B_NAME) $(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) $(B_NAME) checker.c -o $(B_NAME)

clean:
	rm -f $(OBJ)
	rm -f $(B_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus

test: $(NAME)
	$(CC) $(CFLAGS) main.c
	make clean
	clear
	./a.out