/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:57:13 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/16 18:30:17 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b, int index)
{
	ra(stack_a, index);
	rb(stack_b, index);
	if (index == 1)
		write(1, "rr\n", 3);
}
