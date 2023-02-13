/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:07:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/13 16:58:05 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    rrb(t_list **stack_b)
{
    t_list  *lst;
    t_list  *head;
    t_list  *tmp;

    head = (*stack_b);
    lst = ft_lstlast(head);
    tmp = before_last(head);
    lst->next = head;
    tmp->next = NULL;
    (*stack_b) = lst;
}
