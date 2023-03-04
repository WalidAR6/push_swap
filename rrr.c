/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:50:33 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/04 16:32:30 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    rrr(t_list **stack_a, t_list **stack_b, int index)
{
    rra(stack_a, index);
    rrb(stack_b, index);
    if (index == 1)
        write(1, "rrr\n", 4);
}