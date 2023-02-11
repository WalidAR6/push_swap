/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:41:05 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/11 21:22:25 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static size_t	check_num_word(char const *s, char c)
{
	size_t	i;
	size_t	st;
	size_t	num;

	st = 0;
	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] == c)
			st = 0;
		else if (st == 0)
		{
			st = 1;
			num++;
		}
		i++;
	}
	return (num);
}

static size_t	check_num_char(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **p, size_t index)
{
	size_t	i;

	i = 0;
	if (!p)
		return ;
	while (p[i] && i < index)
		free(p[i++]);
	free(p);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**p;

	i = 0;
	if (!s)
		return (NULL);
	words = check_num_word(s, c);
	p = (char **)malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		p[i] = (char *)malloc((check_num_char(s, c) + 1) * sizeof(char));
		if (!p[i])
			return (ft_free(p, i), NULL);
		ft_strlcpy(p[i], s, check_num_char(s, c) + 1);
		s = s + check_num_char(s, c);
		i++;
	}
	p[i] = NULL;
	return (p);
}