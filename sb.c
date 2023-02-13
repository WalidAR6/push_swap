/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:57:56 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/13 11:36:33 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    sb(t_list **stack_b)
{
    t_list  *tmp;
    t_list  *sec;
    t_list  *head;

    if (ft_lstsize((*stack_b)) <= 1)
        return ;
    head = (*stack_b);
    sec = head->next;
    tmp = head;
    head->next = sec->next;
    sec->next = tmp;
    (*stack_b) = sec;
}