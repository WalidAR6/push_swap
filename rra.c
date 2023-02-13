/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:41:40 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/13 16:58:22 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_list  *before_last(t_list *list)
{
    int i;
    int l;

    i = 0;
    l = ft_lstsize(list) - 1;
    while (i < l - 1)
    {
        list = list->next;
        i++;
    }
    return (list);      
}

void    rra(t_list **stack_a)
{
    t_list  *lst;
    t_list  *head;
    t_list  *tmp;

    head = (*stack_a);
    lst = ft_lstlast(head);
    tmp = before_last(head);
    lst->next = head;
    tmp->next = NULL;
    (*stack_a) = lst;
}