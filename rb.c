/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:53 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/13 17:55:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    rb(t_list **stack_b)
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
}