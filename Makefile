NAME = push_swap.a

SRC = sources/ft_printf.c\
	sources/sources1.c\
	sources/sources2.c\
	sources/ft_split.c\
	operations_a.c\
	operations_b.c\
	quicksort.c\
	source1.c\
	sort_3.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(NAME) push_swap.c -o push_swap

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f push_swap

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus