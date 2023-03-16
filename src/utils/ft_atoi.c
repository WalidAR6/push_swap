/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:27:15 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/15 16:39:09 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_condition(t_vars *vars, ssize_t res, int sign)
{
	if (res * sign > INT_MAX || res * sign < INT_MIN)
	{
		write(2, "Error\n", 7);
		if (vars->stack_a)
			free_list(vars);
		free_double(vars);
		exit(1);
	}
}

int	ft_atoi(t_vars *vars, const char *str)
{
	int		i;
	int		sign;
	ssize_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			break ;
	}
	check_condition(vars, res, sign);
	return ((int)res * sign);
}
