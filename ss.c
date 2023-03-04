/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:00:35 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/04 19:42:58 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    ss(t_list **stack_a, t_list **stack_b, int index)
{
    sa(stack_a, index);
    sb(stack_b, index);
    if (index == 1)
        write(1, "ss\n", 3);
}