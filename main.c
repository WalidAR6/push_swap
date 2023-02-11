/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/06 18:55:27 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_stack(t_vars *vars, char *arg, int i)
{
    int l;

    l = ft_atoi(arg);
    if (l == -1)
    {
        write(2, "Error you passed the int limit\n", 17);
        exit(1);
    }
    vars->stack_a[i] = l;
}

void    is_duplicated(char **str)
{
    int i;
    int j;
    
    i = 1;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (!ft_strcmp(str[i], str[j]))
            {
                write(2, "duplicated", 11);
                exit(1);
            }
            
            j++;
        }
        i++;
    }
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
        is_duplicated(av);
        while (av[++i])
        {
            ft_isdigit(av[i]);
            fill_stack(&vars, av[i], j);
            j++;
        }
        fill_list(&vars, av);
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