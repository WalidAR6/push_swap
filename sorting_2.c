/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:30:49 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/21 01:53:05 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_tab(t_vars *vars)
{
    t_list *head;
    int i;

    i = 0;
    head = vars->stack_a;
    while (head && i < vars->size)
    {
        vars->tab[i] = head->content;
        head = head->next;
        i++;
    }
}

void     list_element(t_vars *vars)
{   
    vars->tab = (int *) malloc(sizeof(int) * vars->size);
    if (!vars->tab)
        return ;
    fill_tab(vars);
}
void    pos_lis(t_vars *vars)
{
    int i;

    i = 0;
    vars->lis = (int *) malloc(sizeof(int) * vars->size);
    if (!vars->lis)
        return ;
    vars->pos = (int *) malloc(sizeof(int) * vars->size);
    if (!vars->pos)
        return ;
    while (i < vars->size)
    {
        vars->lis[i] = 1;
        vars->pos[i] = -1;
        i++;
    }
}

void    find_lis(t_vars *vars)
{
    pos_lis(vars);
}

void    sort_more_five(t_vars *vars)
{
    vars->size = ft_lstsize(vars->stack_a);    
    list_element(vars);
    find_lis(vars);
//     int i = 0;
//     while (i < ft_lstsize(vars->stack_a))
//     {
//         printf("%d\n",vars->pos[i]);
//         i++;
//     }
// }