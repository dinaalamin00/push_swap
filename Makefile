SRC = main.c errors.c utils.c str_to_int.c lst.c moves.c parsing.c sort.c mini_sort.c
BONUS = checker.c exec_move.c errors.c moves.c parsing.c lst.c utils.c str_to_int.c gnl/get_next_line.c gnl/get_next_line_utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
BONOBJ = ${BONUS:.c=.o}
LIBFTA = libft/libft.a
NAME = push_swap
BNAME = checker


all: $(NAME)

$(NAME): $(OBJ)
	make all -C libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFTA) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@
	
bonus: $(BONOBJ)
	make all -C libft
	$(CC) $(CFLAGS) $(BONUS) $(LIBFTA) -o $(BNAME)

clean:
	make clean -C libft
	rm -f $(OBJ) $(BONOBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(BNAME)

re: fclean all

reb: fclean bonus