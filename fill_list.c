/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:07:32 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/25 18:35:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_list(t_vars *vars, int l)
{
    t_list  *new;

    if (vars->counter == 0)
    {
        vars->stack_a = ft_lstnew(l);
        vars->counter++;
    }
    else
    {
        new = ft_lstnew(l);
        ft_lstadd_back(&vars->stack_a, new);
    }
}
 