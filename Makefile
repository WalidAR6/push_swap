NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = main

OBJ = $(SRCS:=.o)

all: $(NAME)

%.o:%.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all