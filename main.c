/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/13 17:44:54 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_stack(t_vars *vars)
{
    int l;
    int i;

    i = 0;
    while (vars->s_args[i])
    {
        l = ft_atoi(vars->s_args[i]);
        fill_list(vars, l);
        i++;
    }   
}

char    **join_args(t_vars *vars, char **av)
{
    int i;

    i = 0;
    while (av[++i])
    {
        vars->args = ft_strjoin_sep(vars->args, av[i], " ");
    }
    return (ft_split(vars->args, ' '));
}

void    validate_args(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->s_args[i])
    {
        ft_isdigit(vars->s_args[i]);
        i++;
    }
}

void    dup_num(t_vars *vars)
{
    t_list *tmp;
    t_list  *head;

    head = vars->stack_a;
    while (head)
    {
        tmp = head->next;
        while (tmp)
        {
            if (head->content == tmp->content)
            {
                write(2, "duplicated", 11);
                exit(1);
            }
            tmp = tmp->next;
        }
        head = head->next;
    }
}

int main(int ac, char **av)
{
    t_vars  vars;

    if (ac > 1)
    {
        vars.s_args = join_args(&vars, av);
        validate_args(&vars);
        fill_stack(&vars);
        if (ft_lstsize(vars.stack_a) == 1)
            return (0);
        dup_num(&vars);
        ra(&vars.stack_a);
        printf("-----------stack_a-------------\n");
        while (vars.stack_a)
        {
            printf("%d\n",vars.stack_a->content);
            vars.stack_a = vars.stack_a->next;
        }
        printf("-----------stack_b-------------\n");
        while (vars.stack_b)
        {
            printf("%d\n",vars.stack_b->content);
            vars.stack_b = vars.stack_b->next;
        }
    }
}
