/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:30:36 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/06 21:04:39 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *head;
    t_list  *tmp;
    t_list  *tmp_2;
    
    if (!(*stack_b))
        return ;
    if(!(*stack_a))
    {
        tmp = (*stack_b);
        head = tmp->next;
        (*stack_a) = tmp;
        (*stack_a)->next = NULL;
        (*stack_b) = head;
    }
    else
    {
        tmp = (*stack_b);
        head = tmp->next;
        tmp_2 = (*stack_a);
        tmp->next = tmp_2;
        (*stack_b) = head;
        (*stack_a) = tmp;
    }
    write(1, "pa\n", 3);
}