/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:09:27 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 18:31:21 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				num_moves;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_vars
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			counter;
	char		*args;
	char		**s_args;
	int			*tab;
	int			*lis;
	int			*pos;
	int			size;
	int			*res;
	int			li_len;
	int			li_pos;
	int			min_lar;
}				t_vars;

t_list	*ft_lstnew(int content);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
void	ft_isdigit(char *str);
char	*ft_strnstr(const char *str, const char *look, size_t n);
char	*ft_strstr(const char *str, const char *look);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	**join_args(t_vars *vars, char **av);
int		is_sorted(t_vars *vars);
void	validate_args(t_vars *vars);
void	fill_stack(t_vars *vars);
void	dup_num(t_vars *vars);
void	fill_list(t_vars *vars, int l);
char	*ft_strjoin_sep(char *s1, char *s2, char *sep);
char	**ft_split(char const *s, char c);
int		ft_lstsize(t_list *lst);
void	sa(t_list **stack_a, int index);
void	sb(t_list **stack_b, int index);
void	ss(t_list **stack_a, t_list **stack_b, int index);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int idnex);
void	rrb(t_list **stack_b, int idnex);
t_list	*before_last(t_list *list);
void	rrr(t_list **stack_a, t_list **stack_b, int idnex);
void	ra(t_list **stack_a, int index);
void	rb(t_list **stack_b, int index);
void	rr(t_list **stack_a, t_list **stack_b, int index);
void	ft_sorting(t_vars *vars);
void	sort_till_five(t_vars *vars);
void	sort_three(t_vars *vars);
void	sort_more_five(t_vars *vars);
int		max_pos(t_list *vars);
int		min_pos(t_list *vars);
int		low_elem(t_list *vars);
int		lar_elem(t_list *vars);
void	list_element(t_vars *vars);
void	fill_tab(t_vars *vars);
void	find_lis(t_vars *vars);
void	pos_lis(t_vars *vars);
void	fill_lis(t_vars *vars);
void	fill_res(t_vars *vars);
int		next_gre(t_vars *vars, int tmp);
int		get_li_pos(int *arr, int size);
int		get_lis(int *arr, int size);
void	calculate_num_moves(t_vars *vars);
void	index_stack_a_elem(t_vars *vars);
int		moves_num(t_vars *vars, int n, int index);
void	move_elem_to_top(t_vars *vars);
int		get_min_lar_pos(t_vars *vars);
void	push_min_to_top(t_vars *vars);
int		is_existe(t_vars *vars, int n, int *arr);
void	not_belong_b(t_vars *vars);
void	ft_free_args(t_vars *vars);
void	free_list(t_vars *vars);
void	free_double(t_vars *vars);

#endif