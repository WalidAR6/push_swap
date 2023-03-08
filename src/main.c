/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/08 12:40:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac > 1)
	{
		vars.s_args = join_args(&vars, av);
		validate_args(&vars);
		fill_stack(&vars);
		if (ft_lstsize(vars.stack_a) == 1)
			return (0);
		dup_num(&vars);
		ft_sorting(&vars);
		ft_free_args(&vars);
	}
	return (0);
}
