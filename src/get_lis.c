/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:22:47 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 13:48:04 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	fill_tab(t_vars *vars)
{
	t_list	*head;
	int		i;

	i = 0;
	head = vars->stack_a;
	while (head && i < vars->size)
	{
		vars->tab[i] = head->content;
		head = head->next;
		i++;
	}
}

void	list_element(t_vars *vars)
{
	vars->tab = (int *) malloc(sizeof(int) * vars->size);
	if (!vars->tab)
		return ;
	fill_tab(vars);
}

void	pos_lis(t_vars *vars)
{
	int	i;

	i = 0;
	vars->lis = (int *) malloc(sizeof(int) * vars->size);
	if (!vars->lis)
		return ;
	while (i < vars->size)
	{
		vars->lis[i] = 1;
		i++;
	}
}

void	fill_lis(t_vars *vars)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < vars->size)
	{
		if (i + 1 == vars->size)
			j = 0;
		else
			j = i + 1;
		tmp = vars->tab[i];
		while (j <= vars->size && vars->tab[i] != vars->tab[j])
		{
			if (tmp < vars->tab[j])
			{
				vars->lis[i] += 1;
				tmp = vars->tab[j];
			}
			j++;
			if (j == vars->size)
				j = 0;
		}
		i++;
	}
}

void	find_lis(t_vars *vars)
{
	pos_lis(vars);
	fill_lis(vars);
	fill_res(vars);
}
