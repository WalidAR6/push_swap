/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:56:23 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/06 17:58:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    sa(t_vars *vars)
{
    int tmp;

    tmp = vars->stack_a[0];
    vars->stack_a[0] = vars->stack_a[1];
    vars->stack_a[1] = tmp;
}