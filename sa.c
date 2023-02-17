/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:56:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/17 11:04:23 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    sa(t_list **stack_a)
{
    t_list  *tmp;
    t_list  *sec;
    t_list  *head;

    if (ft_lstsize((*stack_a)) <= 1)
        return ;
    head = (*stack_a);
    sec = head->next;
    tmp = head;
    head->next = sec->next;
    sec->next = tmp;
    (*stack_a) = sec;
    write(1, "sa\n", 3);
}