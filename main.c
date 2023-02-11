/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/11 16:13:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_stack(t_vars *vars, char *arg)
{
    int l;

    l = ft_atoi(arg);
    fill_list(vars, l);
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

    i = 0;
    if (ac > 2)
    {
        is_duplicated(av);
        vars.counter = 0;
        while (av[++i])
        {
            ft_isdigit(av[i]);
            fill_stack(&vars, av[i]);
        }
        // sa(&vars);
        while (vars.stack_a)
        {
            printf("%d\n", vars.stack_a->content);
            vars.stack_a = vars.stack_a->next;
        }
    }
}
