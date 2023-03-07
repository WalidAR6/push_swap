/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:27:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/07 14:05:24 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	lar_elem(t_list *vars)
{
	int	lrg;

	lrg = vars->content;
	while (vars->next)
	{
		if (vars->content < vars->next->content && lrg < vars->next->content)
			lrg = vars->next->content;
		vars = vars->next;
	}
	return (lrg);
}

int	low_elem(t_list *vars)
{
	int	min;

	min = vars->content;
	while (vars->next)
	{
		if (vars->content > vars->next->content && min > vars->next->content)
			min = vars->next->content;
		vars = vars->next;
	}
	return (min);
}

int	min_pos(t_list *vars)
{
	t_list	*head;
	int		min;
	int		pos;

	pos = 0;
	head = vars;
	min = low_elem(head);
	while (head)
	{
		if (head->content == min)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}

int	max_pos(t_list *vars)
{
	t_list	*head;
	int		max;
	int		pos;

	pos = 0;
	head = vars;
	max = lar_elem(head);
	while (head)
	{
		if (head->content == max)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}

void	ft_sorting(t_vars *vars)
{
	int	l;

	l = ft_lstsize(vars->stack_a);
	if (l <= 3)
		sort_three(vars);
	else if (l == 4 || l == 5)
		sort_till_five(vars);
	else if (l > 5)
		sort_more_five(vars);
}
