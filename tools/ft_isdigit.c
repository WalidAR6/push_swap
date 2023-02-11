/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:41:48 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/11 17:06:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    printf_err()
{
    write(2, "Error, you enter a wrong elements in your args\n", 48);
    exit(1);
}

void	ft_isdigit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '-' || str[i] == '+')
        {
            if (str[i + 1] == '-' || str[i + 1] == '+')
                printf_err();
        }
        else if(!(str[i] >= 48 && str[i] <= 57) && str[i] != '-' && str[i] != '+')
            printf_err();
        i++;
    }
}