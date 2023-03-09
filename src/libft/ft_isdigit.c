/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:48 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/09 16:36:36 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_isdigit(t_vars *vars, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == '\0')
			{
				write(2, "Error\n", 7);
				free_double(vars);
				exit(1);
			}
		}
		else if (!(str[i] >= 48 && str[i] <= 57)
			&& str[i] != '-' && str[i] != '+')
		{
			write(2, "Error\n", 7);
			free_double(vars);
			exit(1);
		}
		i++;
	}
}
