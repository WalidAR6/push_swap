/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:40:41 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/06 22:41:39 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sort(t_vars *vars, t_list *head)
{
    if (min_pos(head) > ft_lstsize(head) / 2)
    {
        if (min_pos(head) == ft_lstsize(head) - 1)
            rra(&vars->stack_a, 0);
        else if (min_pos(head) == ft_lstsize(head) - 2)
        {
            rra(&vars->stack_a, 0);
            rra(&vars->stack_a, 0);
        }
    }
    else if (min_pos(head) <= ft_lstsize(head) / 2)
    {
        if (min_pos(head) == ft_lstsize(head) / 2)
        {
            ra(&vars->stack_a, 0);
            ra(&vars->stack_a, 0);
        }
        else if (min_pos(head) == (ft_lstsize(head) / 2) - 1)
            ra(&vars->stack_a, 0);
    }
}

void    sort_till_five(t_vars *vars)
{
    t_list  *head;
    int size;
    int i;

    i = 3;
    head = vars->stack_a;
    size = ft_lstsize(head);
    while (i < size)
    {
        sort(vars, head);
        pb(&vars->stack_a,&vars->stack_b);
        head = vars->stack_a;
        i++;
    }
    sort_three(vars);
    pa(&vars->stack_a,&vars->stack_b);
    pa(&vars->stack_a,&vars->stack_b);
}