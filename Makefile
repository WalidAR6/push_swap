NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror 

SRCS = main\
		src/utils/ft_lstnew\
		src/utils/ft_strdup\
		src/utils/ft_strlen\
		src/utils/ft_strlcpy\
		src/utils/ft_lstadd_back\
		src/utils/ft_lstadd_front\
		src/utils/ft_lstlast\
		src/utils/ft_isdigit\
		src/utils/ft_strnstr\
		src/utils/ft_strstr\
		src/utils/ft_strncmp\
		src/utils/ft_strcmp\
		src/utils/ft_atoi\
		src/fill_list\
		src/utils/ft_strjoin_sep\
		src/utils/ft_split\
		src/utils/ft_lstsize\
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
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all