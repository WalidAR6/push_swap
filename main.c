/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/16 13:09:43 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	init_args(t_vars *vars)
{
	vars->stack_a = NULL;
	vars->stack_b = NULL;
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac > 1)
	{
		init_args(&vars);
		vars.s_args = join_args(&vars, av);
		if (!vars.s_args[0])
			return (0);
		validate_args(&vars);
		fill_stack(&vars);
		if (ft_lstsize(vars.stack_a) == 1)
		{
			ft_free_args(&vars);
			return (0);
		}
		dup_num(&vars);
		ft_sorting(&vars);
		ft_free_args(&vars);
	}
	return (0);
}
