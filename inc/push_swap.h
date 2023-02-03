#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    int     content;
    struct  s_list *next;
}               t_list;

typedef struct s_vars
{
    int     *stack_a;
    int     *stack_b;
    t_list  *list;
}           t_vars;

t_list	*ft_lstnew(int content);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int     ft_atoi(const char *str);

#endif