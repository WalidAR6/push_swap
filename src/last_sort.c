/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:38:50 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 12:41:20 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    stack_a_to_top(t_vars *vars)
{
    t_list *head;
    int i;

    i = 0;
    head = vars->stack_a;
    while (i < ft_lstsize(head))
    {
        if (get_min_lar_pos(vars) == 0)
            break;
        else if (get_min_lar_pos(vars) > ft_lstsize(head) / 2)
            rra(&vars->stack_a, 0);
        else if (get_min_lar_pos(vars) <=ft_lstsize(head) / 2)
            ra(&vars->stack_a, 0);
        head = vars->stack_a;
        i++;
    }
}

void    elem_min_greater(t_vars *vars, int n)
{
    t_list *head_a;

    head_a = vars->stack_a;
    vars->min_lar = lar_elem(head_a);
    while (head_a)
    {
        if (n < head_a->content && vars->min_lar >= head_a->content)
            vars->min_lar = head_a->content;
        head_a = head_a->next;
    }
}

int    min_of_moves(t_list *vars)
{
    t_list  *head;
    int     min;

    head = vars;
    min = head->num_moves;
    while (head->next)
    {
        if (head->num_moves > head->next->num_moves && min > head->next->num_moves)
            min = head->next->num_moves;
        head = head->next;
    }
    return (min);
}

int     min_of_moves_pos(t_list *vars)
{
    int i;
    t_list  *head;
    
    i = 0;
    head = vars;
    while (head)
    {
        if (head->num_moves == min_of_moves(head))
            break;
        head = head->next;
        i++;
    }
    return (i);   
}

void    move_elem_to_top(t_vars *vars)
{
    t_list *head_a;
    t_list *head_b;

    head_a = vars->stack_a;
    head_b = vars->stack_b;
    while (head_b)
    {
        if (min_of_moves_pos(head_b) == 0)
        {
            elem_min_greater(vars, head_b->content);
            stack_a_to_top(vars);
            pa(&vars->stack_a, &vars->stack_b);
            break;
        }
        else if (min_of_moves_pos(head_b) > ft_lstsize(head_b) / 2)
            rrb(&vars->stack_b, 0);
        else if (min_of_moves_pos(head_b) <= ft_lstsize(head_b) / 2)
            rb(&vars->stack_b, 0);
        head_b = vars->stack_b;
    }
}