/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:27:37 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/16 20:33:01 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    sort_three(t_vars *vars)
{
    if (vars->stack_a->content > vars->stack_a->next->content)
        sa(&vars->stack_a);
    if (vars->stack_a->next->content > vars->stack_a->next->next->content)
        rra(&vars->stack_a);
}

void    ft_sorting(t_vars *vars)
{
    int l;

    l = ft_lstsize(vars->stack_a);
    if (l <= 3)
        sort_three(vars);
}