/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:30:49 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/27 20:38:00 by waraissi         ###   ########.fr       */
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
    while (i < vars->size)
    {
        vars->lis[i] = 1;
        i++;
    }
}

void    fill_lis(t_vars *vars)
{
    int i;
    int j;
    int tmp;
    
    i = 0;
    while (i < vars->size)
    {
        if (i + 1 == vars->size)
            j = 0;
        else
            j = i + 1;
        tmp = vars->tab[i];
        while (j <= vars->size && vars->tab[i] != vars->tab[j])
        {
            if (tmp < vars->tab[j])
            {
                vars->lis[i] += 1;
                tmp = vars->tab[j];
            }
            j++;
            if (j == vars->size)
                j = 0;
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

int     next_gre(t_vars *vars, int tmp)
{
    int i;

    i = vars->li_pos;
    while (i < vars->size)
    {
        if (vars->tab[i] > tmp)
            break;
        i++;
        if (i == vars->size)
            i = 0;
    }
    return (vars->tab[i]);
}

void    fill_res(t_vars *vars)
{
    int i;
    int tmp;

    i = 1;
    vars->li_len = get_lis(vars->lis, vars->size);
    vars->li_pos = get_li_pos(vars->lis, vars->size);
    vars->res = (int *) malloc(sizeof(int) * vars->li_len);
    if (!vars->res)
        return ;
    vars->res[0] = vars->tab[vars->li_pos];
    tmp = vars->res[0];
    while (i < vars->li_len)
    {
        vars->res[i] = next_gre(vars, tmp);
        tmp = vars->res[i];
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
            ra(&vars->stack_a);
        else
            pb(&vars->stack_a, &vars->stack_b);
        head = vars->stack_a;
        j++;
    }
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

int     moves_num(t_vars *vars, int n, int index)
{
    t_list *head;
    int max;
    int res;
    
    head = vars->stack_a;
    max = lar_elem(head);
    index_stack_a_elem(vars);
    while (head)
    {
        if (n < head->content && max > head->content)
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

void    calculate_num_moves(t_vars *vars)
{
    t_list  *head;
    int i;

    i = 0;
    head = vars->stack_b;
    while (head)
    {
        i = index_stack_elem(vars->stack_b, i);
        head->index = i;
        head->num_moves = moves_num(vars, head->content, head->index);
        head = head->next;
        i++;
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

void    sort_more_five(t_vars *vars)
{
    t_list *head;
    int i;

    vars->size = ft_lstsize(vars->stack_a);
    list_element(vars);
    find_lis(vars);
    not_belong_b(vars);
    calculate_num_moves(vars);
    head = vars->stack_b;
    i = min_of_moves(head);
    
    
    
    // int i = 0;
    // printf("---------------------\n");
    // while (i < ft_lstsize(vars->stack_b))
    // {
    //     printf("%d\n",vars->stack_b->index);
    //     i++;
    // }
    // printf("---------------------\n");
}