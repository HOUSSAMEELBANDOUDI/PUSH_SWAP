/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:24:20 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 17:12:57 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**ft_check(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

size_t	ft_countworld(char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
		if (str[i])
			i++;
	}
	return (count);
}

size_t	ft_len(char *str, char c)
{
	size_t	j;

	j = 0;
	while (str[j] && str[j] != c)
		j++;
	return (j);
}

char	*ft_world(char *str, char c)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc((ft_len(str, c) + 1) * sizeof(char));
	if (!dst)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != c)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split_bonus(char *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_countworld(s, c);
	dst = (char **)malloc((ft_countworld(s, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s && i < j)
	{
		while (*s == c)
			s++;
		dst[i] = ft_world(s, c);
		if (!dst[i])
			return (ft_check(dst));
		i++;
		while (*s != c && *s)
			s++;
	}
	dst[i] = 0;
	return (dst);
}
