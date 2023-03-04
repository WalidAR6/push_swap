/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:53 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/04 16:29:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    rb(t_list **stack_b, int index)
{
    t_list *lst;
    t_list *head;
    t_list  *tmp;

    tmp = (*stack_b);
    head = tmp->next;
    lst = ft_lstlast(head);
    lst->next = tmp;
    tmp->next = NULL;
    (*stack_b) = head;
    if (index == 0)
        write(1, "rb\n", 3);
}