/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:14:18 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/01 20:48:16 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char *str, char sep)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_substrlen(char *str, char sep)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strndup(char *str, int len)
{
	int		i;
	char	*ptr;

	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static	int	ft_skip_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] == sep)
		i++;
	return (i);
}

char	**ft_split(char *str, char sep)
{
	char	**strings;
	int		words;
	int		size;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	words = ft_count_words(str, sep);
	strings = malloc((words + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	strings[words] = NULL;
	i = 0;
	index = 0;
	while (i < words)
	{
		index += ft_skip_sep(&str[index], sep);
		size = ft_substrlen(&str[index], sep);
		strings[i] = ft_strndup(&str[index], size);
		if (!strings[i++])
			return (ft_free(strings), NULL);
		index += size;
	}
	return (strings);
}
