#include "inc/push_swap.h"



void    fill_stack(t_vars *vars, char *arg, int i)
{
    int l;

    l = ft_atoi(arg);
    vars->stack_a[i] = l;
}

int main(int ac, char **av)
{
    t_vars  vars;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (ac > 2)
    {
        vars.stack_a = (int *)malloc(sizeof(int) * (ac - 1));
        if (!vars.stack_a)
            exit(1);
        while (av[++i])
        {
            fill_stack(&vars, av[i], j);
            j++;
        }
        i = 0;
        while (vars.stack_a[i])
        {
            printf("%d\n", vars.stack_a[i]);
            i++;
        }
    }
}












    // t_list *p;
    // t_list *m;
    // t_list *q;
    // int i = 1;
    // (void)ac;
    // p = ft_lstnew(av[1]);
    // m = p;
    // while (av[++i])
    // {
    //     q = ft_lstnew(av[i]);
    //     ft_lstadd_back(&p, q);
    // }
    // while (m)
    // {
    //     printf("%s\n", m->content);
    //     m = m->next;
    // }