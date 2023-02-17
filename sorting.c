/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:27:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/17 12:22:45 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int    lar_elem(t_list *vars)
{
    int lrg;

    lrg = 0;
    while (vars->next)
    {
        if (vars->content < vars->next->content)
            lrg = vars->next->content;
        vars = vars->next;
    }
    return (lrg);
}

int    low_elem(t_list *vars)
{
    int min;

    min = 0;
    while (vars->next)
    {
        if (vars->content > vars->next->content)
            min = vars->next->content;
        vars = vars->next;
    }
    return (min);
        
}
void    sort_three(t_vars *vars)
{   
    t_list  *head;
    t_list  *lst;

    head = vars->stack_a;
    lst = ft_lstlast(vars->stack_a);
    if (head->content > head->next->content
        && head->next->content > head->next->next->content)
        ra(&vars->stack_a);
    else if (head->content == lar_elem(head))
    {
        ra(&vars->stack_a);
    }
    else if (lst->content == low_elem(head))
        rra(&vars->stack_a);
    head = vars->stack_a;
    if (head->content > head->next->content)
        sa(&vars->stack_a);
}

void    sort_till_five(t_vars *vars)
{
    
}

void    ft_sorting(t_vars *vars)
{
    int l;

    l = ft_lstsize(vars->stack_a);
    if (l <= 3)
        sort_three(vars);
    if (l <= 5)
        sort_till_five(vars);
}