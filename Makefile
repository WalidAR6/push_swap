NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = main\
		tools/ft_lstnew\
		tools/ft_strdup\
		tools/ft_strlen\
		tools/ft_strlcpy\
		tools/ft_lstadd_back\
		tools/ft_lstadd_front\
		tools/ft_lstlast

OBJ = $(SRCS:=.o)

all: $(NAME)

%.o:%.c inc/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all