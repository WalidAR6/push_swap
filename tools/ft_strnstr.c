/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:40:58 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/05 22:26:00 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strnstr(const char *str, const char *look, size_t n)
{
	size_t	i;

	i = 0;
	if (!(str && look) && n == 0)
		return (NULL);
	if (ft_strlen(look) == 0)
		return ((char *)str);
	while (str[i] && i + ft_strlen(look) <= n)
	{
		if (ft_strncmp(&str[i], &look[0], ft_strlen(look)) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}