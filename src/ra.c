/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:20:47 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/06 21:04:45 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ra(t_list **stack_a, int index)
{
    t_list *lst;
    t_list *head;
    t_list  *tmp;

    tmp = (*stack_a);
    head = tmp->next;
    lst = ft_lstlast(head);
    lst->next = tmp;
    tmp->next = NULL;
    (*stack_a) = head;
    if (index == 0)
        write(1, "ra\n", 3);
}