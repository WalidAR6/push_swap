/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:27:40 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 13:47:57 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_lis(int *arr, int size)
{
	int	i;
	int	max;

	i = 0;
	max = arr[i];
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1] && arr[i + 1] > max)
			max = arr[i + 1];
		i++;
	}
	return (max);
}

int	get_li_pos(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == get_lis(arr, size))
			break ;
		i++;
	}
	return (i);
}

int	next_gre(t_vars *vars, int tmp)
{
	int	i;

	i = vars->li_pos;
	while (i < vars->size)
	{
		if (vars->tab[i] > tmp)
			break ;
		i++;
		if (i == vars->size)
			i = 0;
	}
	return (vars->tab[i]);
}

void	fill_res(t_vars *vars)
{
	int	i;
	int	tmp;

	i = 1;
	vars->li_len = get_lis(vars->lis, vars->size);
	vars->li_pos = get_li_pos(vars->lis, vars->size);
	vars->res = (int *) malloc(sizeof(int) * vars->li_len);
	if (!vars->res)
		return ;
	vars->res[0] = vars->tab[vars->li_pos];
	tmp = vars->res[0];
	while (i < vars->li_len)
	{
		vars->res[i] = next_gre(vars, tmp);
		tmp = vars->res[i];
		i++;
	}
}
