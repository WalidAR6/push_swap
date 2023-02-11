/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:48 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/05 22:19:00 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_isdigit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= 48 && str[i] <= 57))
        {
            write(2, "Error, you enter a wrong elements in your args\n", 48);
            exit(1);
        }
        i++;
    }
}