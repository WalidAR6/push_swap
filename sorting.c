/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:27:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/21 01:39:08 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int    lar_elem(t_list *vars)
{
    int lrg;

    lrg = vars->content;
    while (vars->next)
    {
        if (vars->content < vars->next->content && lrg < vars->next->content)
            lrg = vars->next->content;
        vars = vars->next;
    }
    return (lrg);
}

int    low_elem(t_list *vars)
{
    int min;

    min = vars->content;
    while (vars->next)
    {
        if (vars->content > vars->next->content && min > vars->next->content)
            min = vars->next->content;
        vars = vars->next;
    }
    return (min);
        
}

int     min_pos(t_list  *vars)
{
    t_list  *head;
    int min;
    int pos;

    pos = 0;
    head = vars;
    min = low_elem(head);
    while (head)
    {
        if (head->content == min)
            break;
        pos++;
        head = head->next;
    }
    return (pos);
}

int     max_pos(t_list  *vars)
{
    t_list  *head;
    int max;
    int pos;

    pos = 0;
    head = vars;
    max = lar_elem(head);
    while (head)
    {
        if (head->content == max)
            break;
        pos++;
        head = head->next;
    }
    return (pos);
}

void    sort_three(t_vars *vars)
{
    int max;
    int min;

    max = max_pos(vars->stack_a);
    min = min_pos(vars->stack_a);
    if (min == 1 && max == 2)
        sa(&vars->stack_a);
    else if (min == 2 && max == 1)
        rra(&vars->stack_a);
    else if (min == 2 && max == 0)
    {
        ra(&vars->stack_a);
        sa(&vars->stack_a);
    }
    else if (min == 0 && max == 1)
    {
        rra(&vars->stack_a);
        sa(&vars->stack_a);
    }
    else if ((min == 2 && max == 0) || (min == 1 && max == 0))
        ra(&vars->stack_a);
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
        if (min_pos(head) > ft_lstsize(head) / 2)
        {
            if (min_pos(head) == ft_lstsize(head) - 1)
                rra(&vars->stack_a);
            else if (min_pos(head) == ft_lstsize(head) - 2)
            {
                rra(&vars->stack_a);
                rra(&vars->stack_a);
            }
        }
        else if (min_pos(head) <= ft_lstsize(head) / 2)
        {
            if (min_pos(head) == ft_lstsize(head) / 2)
            {
                ra(&vars->stack_a);
                ra(&vars->stack_a);
            }
            else if (min_pos(head) == (ft_lstsize(head) / 2) - 1)
                ra(&vars->stack_a);
        }
        pb(&vars->stack_a,&vars->stack_b);
        head = vars->stack_a;
        i++;
    }
    sort_three(vars);
    pa(&vars->stack_a,&vars->stack_b);
    pa(&vars->stack_a,&vars->stack_b);
}

void    ft_sorting(t_vars *vars)
{
    int l;

    l = ft_lstsize(vars->stack_a);
    if (l <= 3)
        sort_three(vars);
    else if (l == 4 || l ==5)
        sort_till_five(vars);
    else if (l > 5)
        sort_more_five(vars);
}