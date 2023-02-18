/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:27:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/18 16:38:23 by waraissi         ###   ########.fr       */
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
void    sort_more_five(t_vars *vars)
{
    (void)vars;
}

void    sort_three(t_vars *vars)
{   
    t_list  *head;

    head = vars->stack_a;
    if (head->content > head->next->content
            && head->next->content < head->next->next->content)
        sa(&vars->stack_a);
    else if (head->content > head->next->content
                && head->next->content > head->next->next->content)
    {
        sa(&vars->stack_a);
        rra(&vars->stack_a);
    }
    else if (head->content < head->next->content
                && head->next->content > head->next->next->content)
    {
        sa(&vars->stack_a);
        ra(&vars->stack_a);
    }
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
                ra(&vars->stack_a);
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