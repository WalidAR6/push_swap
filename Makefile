NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = main\
		src/libft/ft_lstnew\
		src/libft/ft_strdup\
		src/libft/ft_strlen\
		src/libft/ft_strlcpy\
		src/libft/ft_lstadd_back\
		src/libft/ft_lstadd_front\
		src/libft/ft_lstlast\
		src/libft/ft_isdigit\
		src/libft/ft_strnstr\
		src/libft/ft_strstr\
		src/libft/ft_strncmp\
		src/libft/ft_strcmp\
		src/libft/ft_atoi\
		src/fill_list\
		src/libft/ft_strjoin_sep\
		src/libft/ft_split\
		src/libft/ft_lstsize\
		src/sa\
		src/sb\
		src/ss\
		src/pb\
		src/pa\
		src/rra\
		src/rrb\
		src/rrr\
		src/ra\
		src/rb\
		src/rr\
		src/sorting\
		src/sort_more_five\
		src/parser\
		src/sort_three\
		src/sort_five\
		src/fill_res\
		src/get_lis\
		src/last_sort\
		src/ft_free\
		src/num_moves_calc



OBJ = $(SRCS:=.o)

all: $(NAME)

%.o:%.c inc/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@ -g

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all