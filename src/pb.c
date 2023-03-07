/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:05:03 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 13:52:46 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*tmp_2;

	if (!(*stack_a))
		return ;
	if (!(*stack_b))
	{
		tmp = (*stack_a);
		head = tmp->next;
		(*stack_b) = tmp;
		(*stack_b)->next = NULL;
		(*stack_a) = head;
	}
	else
	{
		tmp = (*stack_a);
		head = tmp->next;
		tmp_2 = (*stack_b);
		tmp->next = tmp_2;
		(*stack_a) = head;
		(*stack_b) = tmp;
	}
	write(1, "pb\n", 3);
}
