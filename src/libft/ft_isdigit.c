/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:48 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/13 17:12:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_sign(t_vars *vars, char c)
{
	if (c == '-' || c == '+' || c == '\0')
	{
		write(2, "Error\n", 8);
		free_double(vars);
		exit(1);
	}
}

void	after(t_vars *vars, char c)
{
	if ((c <= '0' || c >= '9') && c != '\0')
	{
		write(2, "Error\n", 8);
		free_double(vars);
		exit(1);
	}
}

void	ft_isdigit(t_vars *vars, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			check_sign(vars, str[i + 1]);
		if (str[i] >= '0' && str[i] <= '9')
			after(vars, str[i + 1]);
		else if (!(str[i] >= 48 && str[i] <= 57)
			&& str[i] != '-' && str[i] != '+')
		{
			write(2, "Error\n", 8);
			free_double(vars);
			exit(1);
		}
		i++;
	}
}
