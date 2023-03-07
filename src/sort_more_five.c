/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:30:49 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 12:45:57 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     get_min_lar_pos(t_vars *vars)
{
    int i;
    t_list  *head;

    i = 0;
    head = vars->stack_a;
    while (head)
    {
        if (head->content == vars->min_lar)
            break;
        head = head->next;
        i++;
    }
    return (i);
}

void    push_min_to_top(t_vars *vars)
{
    t_list *head;
    int i;

    i = 0;
    head = vars->stack_a;
    while (i < ft_lstsize(head))
    {
        if (min_pos(head) == 0)
            break;
        else if (min_pos(head) > ft_lstsize(head) / 2)
            rra(&vars->stack_a, 0);
        else if (min_pos(head) <= ft_lstsize(head) / 2)
            ra(&vars->stack_a, 0);
        head = vars->stack_a;
        i++;
    }
}

int     is_existe(t_vars *vars, int n, int *arr)
{
    int i;

    i = 0;
    while (i < vars->li_len)
    {
        if (arr[i] == n)
            return (1);
        i++;
    }
    return (0);
}

void    not_belong_b(t_vars *vars)
{
    t_list  *head;
    int     j;

    j = 0;
    head = vars->stack_a;
    while (j < vars->size)
    {
        if (is_existe(vars, head->content, vars->res))
            ra(&vars->stack_a, 0);
        else
            pb(&vars->stack_a, &vars->stack_b);
        head = vars->stack_a;
        j++;
    }
}

void    sort_more_five(t_vars *vars)
{
    t_list *head;

    vars->size = ft_lstsize(vars->stack_a);
    list_element(vars);
    find_lis(vars);
    not_belong_b(vars);
    calculate_num_moves(vars);
    head = vars->stack_b;
    while (head)
    {
        move_elem_to_top(vars);
        calculate_num_moves(vars);
        head = vars->stack_b;
    }
    push_min_to_top(vars);
}
