/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_moves_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:35:43 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 12:37:25 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     moves_num(t_vars *vars, int n, int index)
{
    t_list *head;
    int res;
    int     max;

    head = vars->stack_a;
    max = lar_elem(head);
    while (head)
    {
        if (n < head->content && max >= head->content)
        {
            max = head->content;
            res = head->index;
        }
        head = head->next;
    }
    if ( res < 0)
        res = -res;
    if ( index < 0)
        index = -index;
    res = res + index;
    return (res);
}

int    index_stack_elem(t_list *vars, int i)
{
    if (i == (ft_lstsize(vars) / 2) + 1)
    {
        if (ft_lstsize(vars) % 2 == 0)
            i = -i + 2;
        else 
            i = -i + 1;      
    }
    return (i);
}

void    index_stack_a_elem(t_vars *vars)
{
    t_list  *head;
    int i;

    i = 0;
    head = vars->stack_a;
    while (head)
    {
        i = index_stack_elem(vars->stack_a, i);
        head->index = i;
        head = head->next;
        i++;
    }
}

void    calculate_num_moves(t_vars *vars)
{
    t_list  *head;
    int i;

    i = 0;
    head = vars->stack_b;
    index_stack_a_elem(vars);
    while (head)
    {
        i = index_stack_elem(vars->stack_b, i);
        head->index = i;
        head->num_moves = moves_num(vars, head->content, head->index);
        head = head->next;
        i++;
    }
}