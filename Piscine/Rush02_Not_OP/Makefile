NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = execute.c ft_putchar.c ft_strlen.c main.c read_dict.c write_1.c write_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
