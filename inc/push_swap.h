/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:09:27 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/12 21:24:46 by waraissi         ###   ########.fr       */
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
    int     content;
    struct  s_list *next;
}               t_list;

typedef struct s_vars
{
    t_list     *stack_a;
    int         counter;
    char        *args;
    char        **s_args;
}           t_vars;

t_list	*ft_lstnew(int content);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int     ft_atoi(const char *str);
void	ft_isdigit(char *str);
char	*ft_strnstr(const char *str, const char *look, size_t n);
char	*ft_strstr(const char *str, const char *look);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_strcmp(const char *s1, const char *s2);
void    sa(t_vars *vars);
void    fill_list(t_vars *vars, int l);
char	*ft_strjoin_sep(char *s1, char *s2, char *sep);
char	**ft_split(char const *s, char c);

#endif