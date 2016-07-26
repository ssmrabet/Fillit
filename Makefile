NAME = fillit

HEAD = fillit.h

SRC = main.c \
	  parse.c \
	  open.c \
	  solve_tetris.c \
	  solve_tools.c \
	  tools.c

LIBFT = libft/

OBJS = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

%.o: %.c $(HEAD)
	$(CC) -c $<

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
