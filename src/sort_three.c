/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:39:25 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 13:53:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_vars *vars)
{
	int	max;
	int	min;

	max = max_pos(vars->stack_a);
	min = min_pos(vars->stack_a);
	if (min == 1 && max == 2)
		sa(&vars->stack_a, 0);
	else if (min == 2 && max == 1)
		rra(&vars->stack_a, 0);
	else if (min == 2 && max == 0)
	{
		ra(&vars->stack_a, 0);
		sa(&vars->stack_a, 0);
	}
	else if (min == 0 && max == 1)
	{
		rra(&vars->stack_a, 0);
		sa(&vars->stack_a, 0);
	}
	else if ((min == 2 && max == 0) || (min == 1 && max == 0))
		ra(&vars->stack_a, 0);
}
