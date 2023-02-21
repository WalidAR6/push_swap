/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:30:49 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/21 19:48:31 by waraissi         ###   ########.fr       */
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

void    fill_lis(t_vars *vars)
{
    int i;
    int j;
    
    i = 1;
    while (i < vars->size)
    {
        j = 0;
        while (j < i)
        {
            if (vars->tab[j] < vars->tab[i])
            {
                if (vars->lis[j] + 1 > vars->lis[i])
                {
                    vars->lis[i] = vars->lis[j] + 1;
                    vars->pos[i] = j;
                }
            }
            j++;
        }
        i++;
    }
}

int get_lis(int *arr, int size)
{
    int i = 0;
    int max = arr[i];

    while (i < size)
    {
        if (arr[i] < arr[i + 1] && arr[i + 1] > max)
            max = arr[i + 1];
        i++;
    }
    return (max);
}

int get_li_pos(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == get_lis(arr, size))
            break;
        i++;
    }
    return (i);
}

int get_next_pos(int *arr, int num, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == num)
            break;
        i++;
    }
    return (i);
}

void    fill_res(t_vars *vars)
{
    int i;
    int l_po;
    int p;

    i = 1;
    vars->li = get_lis(vars->lis, vars->size);
    vars->res = (int *) malloc(sizeof(int) * vars->li);
    if (!vars->res)
        return ;
    vars->li_pos = get_li_pos(vars->lis, vars->size);
    vars->res[0] = vars->tab[vars->li_pos];
    l_po = vars->pos[vars->li_pos];
    while (i < vars->li)
    {
        vars->res[i] = vars->tab[l_po];
        p = get_next_pos(vars->tab, vars->tab[l_po], vars->size);
        l_po = vars->pos[p];
        i++;
    }
}

void    find_lis(t_vars *vars)
{
    pos_lis(vars);
    fill_lis(vars);
    fill_res(vars);
}

int     is_existe(t_vars *vars, int n, int *arr)
{
    int i;

    i = 0;
    while (i < vars->li)
    {
        if (arr[i] == n)
            return (1);
        i++;
    }
    return (0);
}

void    start_sorting(t_vars *vars)
{
    t_list  *head;
    int     j;

    j = 0;
    head = vars->stack_a;
    while (j < vars->size)
    {
        if (is_existe(vars, head->content, vars->res))
            ra(&vars->stack_a);
        else
            pb(&vars->stack_a, &vars->stack_b);
        head = vars->stack_a;
        j++;
    }
}

void    min_to_head(t_vars *vars)
{
    t_list *head;
    int i;

    i = 0;
    head = vars->stack_a;
    while (i <= vars->size / 2)
    {
        if (min_pos(head) == 0)
            break;
        if (min_pos(head) > vars->size / 2)
            rra(&vars->stack_a);
        if (min_pos(head) <= vars->size / 2)
            ra(&vars->stack_a);
        head = vars->stack_a;
        i++;   
    }
    
}

void    sort_more_five(t_vars *vars)
{
    vars->size = ft_lstsize(vars->stack_a);    
    min_to_head(vars);
    list_element(vars);
    find_lis(vars);
    start_sorting(vars);
}