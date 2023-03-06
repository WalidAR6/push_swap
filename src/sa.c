/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:56:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/06 21:05:07 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sa(t_list **stack_a, int index)
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
    if (index == 0)
        write(1, "sa\n", 3);
}