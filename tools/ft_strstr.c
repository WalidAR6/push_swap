/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:49:15 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/06 15:50:45 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strstr(const char *str, const char *look)
{
	size_t	i;

	i = 0;
	if (!(str && look))
		return (NULL);
	if (ft_strlen(look) == 0)
		return ((char *)str);
	while (str[i])
	{
		if (ft_strcmp(&str[i], &look[0]) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}