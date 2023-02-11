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
		tools/ft_lstlast\
		tools/ft_isdigit\
		tools/ft_strnstr\
		tools/ft_strstr\
		tools/ft_strncmp\
		tools/ft_strcmp\
		tools/ft_atoi\
		fill_list
		# sa

OBJ = $(SRCS:=.o)

all: $(NAME)

%.o:%.c inc/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@ -g

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all