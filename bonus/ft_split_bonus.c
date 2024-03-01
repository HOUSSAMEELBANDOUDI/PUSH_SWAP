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

int	count_words_bonus(char *str, char c)
{
	int	count;
	int	i;

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

char	*get_next_word_bonus(char *str, char separator)
{
	static int	cursor;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((len + 1) * sizeof(char));
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split_bonus(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words_bonus(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = (char **)malloc(sizeof(char *) * ((words_number + 2)));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word_bonus(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
