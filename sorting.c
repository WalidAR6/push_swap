/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:27:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/17 22:27:23 by waraissi         ###   ########.fr       */
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
    if (head->next->next && head->content > head->next->content
        && head->next->content > head->next->next->content)
        ra(&vars->stack_a);
    else if (head->content == lar_elem(head))
        ra(&vars->stack_a);
    else if (lst->content == low_elem(head))
        rra(&vars->stack_a);
    head = vars->stack_a;
    if (head->content > head->next->content)
        sa(&vars->stack_a);
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

    head = vars->stack_a;
    size = ft_lstsize(head) - 1;
    
    if (min_pos(head) > size / 2)
    {
        if (min_pos(head) == size)
            rra(&vars->stack_a);
        if (min_pos(head) == size - 1)
        {
            ra(&vars->stack_a);
            ra(&vars->stack_a);
        }
    }
    else if (min_pos(head) <= size / 2)
    {
        if (min_pos(head) == size / 2)
        {
            ra(&vars->stack_a);
            ra(&vars->stack_a);
        }
    }
    pb(&vars->stack_a,&vars->stack_b);
    sort_three(vars);
    // pb(&vars->stack_a,&vars->stack_b);
    // sort_three(vars);
    // pa(&vars->stack_a,&vars->stack_b);
    // pa(&vars->stack_a,&vars->stack_b);
    printf("-----------stack_a-------------\n");
    while (vars->stack_a)
    {
        printf("%d\n",vars->stack_a->content);
        vars->stack_a = vars->stack_a->next;
    }
    printf("-----------stack_b-------------\n");
    while (vars->stack_b)
    {
        printf("%d\n",vars->stack_b->content);
        vars->stack_b = vars->stack_b->next;
    }
}

void    ft_sorting(t_vars *vars)
{
    int l;

    l = ft_lstsize(vars->stack_a);
    if (l <= 3)
        sort_three(vars);
    if (l == 4 || l ==5)
        sort_till_five(vars);
}