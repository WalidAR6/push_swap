/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:07:32 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/06 18:56:25 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_list(t_vars *vars, char **str)
{
    t_list *p;
    t_list *m;
    t_list *q;
    int i = 1;
    p = ft_lstnew(str[1]);
    m = p;
    while (str[++i])
    {
        q = ft_lstnew(str[i]);
        ft_lstadd_back(&p, q);
    }
}