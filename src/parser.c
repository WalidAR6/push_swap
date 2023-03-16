/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:16:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/16 15:26:26 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	** join_args(t_vars *vars, char **av)
{
	int		i;

	i = 1;
	vars->args = NULL;
	while (av[i])
	{
		vars->args = ft_strjoin_sep(vars->args, av[i], " ");
		i++;
	}
	return (ft_split(vars->args, ' '));
}

void	validate_args(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->s_args[i])
	{
		ft_isdigit(vars, vars->s_args[i]);
		i++;
	}
}

int	is_sorted(t_vars *vars)
{
	t_list	*head;
	t_list	*tmp;

	head = vars->stack_a;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->content >= tmp->content)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

void	check_sorted(t_vars *vars)
{
	if (is_sorted(vars) == 0)
	{
		free_double(vars);
		free_list(vars);
		exit(0);
	}
}

void	dup_num(t_vars *vars)
{
	t_list	*tmp;
	t_list	*head;

	head = vars->stack_a;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->content == tmp->content)
			{
				write(2, "Error\n", 7);
				free_double(vars);
				free_list(vars);
				exit(0);
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
	check_sorted(vars);
}
