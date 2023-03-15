/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:23:16 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/15 19:07:16 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_double(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->s_args[i])
	{
		free(vars->s_args[i]);
		i++;
	}
	free(vars->s_args);
}

void	free_list(t_vars *vars)
{
	t_list	*tmp;
	t_list	*head;

	tmp = vars->stack_a;
	head = vars->stack_a;
	while (head)
	{
		head = head->next;
		vars->stack_a = head;
		free(tmp);
		tmp = head;
	}
}

void	ft_free_args(t_vars *vars)
{
	free_double(vars);
	if (ft_lstsize(vars->stack_a) > 5)
	{
		free(vars->lis);
		free(vars->res);
	}
	free_list(vars);
}
