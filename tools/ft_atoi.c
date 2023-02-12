/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:27:15 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/12 19:41:15 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_err()
{
	write(2, "Error you passed the int limit\n", 32);
    exit(1);
}

void	after_num(char *str, int i)
{
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
    	{
    	    printf("err\n");
    	    exit(1);
    	}
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	ssize_t		res;

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
			break;
	}
    after_num((char *)str, i);
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		print_err();
	return ((int)res * sign);
}