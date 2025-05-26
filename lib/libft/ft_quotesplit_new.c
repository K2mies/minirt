/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotesplit_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:14:27 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/20 14:53:26 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	wordcount(t_quospl *split, char const *s, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			split->in_double = !split->in_double;
		else if (s[i] == '\'' && split->in_double == 0)
			split->in_single = !split->in_single;
		if (s[i] != c && trigger == 0 && !split->in_single && !split->in_double)
		{
			trigger = 1;
			split->word_count++;
		}
		else if (s[i] == c && (!split->in_single || !split->in_double))
			trigger = 0;
		i++;
	}
	return (split->word_count);
}

static char	*makeword(t_quospl *split, const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		if (s[start] == '\"')
		{
			split->in_double = !split->in_double;
			start++;
		}
		else if (s[start] == '\'' && split->in_double == 0)
		{
			split->in_single = !split->in_single;
			start++;
		}
		if ((split->in_double && s[start] == '"') || (split->in_double && split->in_single && s[start] == '\''))
			start++;
		else
		{
			word[i] = s[start];
			i++;
			start++;
		}
	}
	word[i] = 0;
	return (word);
}

static char	**arrclean(char **array, int index)
{
	if (array == NULL)
		return (NULL);
	while (index >= 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
	return (NULL);
}

static char	**ft_quotesplit2(t_quospl *split, char const *s, char c, int index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == '\"')
			split->in_double = !split->in_double;
		else if (s[i] == '\'' && split->in_double == 0)
			split->in_single = !split->in_single;
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || !s[i]) && index >= 0 && !split->in_single && !split->in_double)
		{
			split->arr[j] = makeword(split, s, index, i);
			if (split->arr[j++] == NULL)
				return (arrclean(split->arr, j));
			index = -1;
		}
		i++;
	}
	split->arr[j] = 0;
	return (NULL);
}

char	**ft_quotesplit(char const *s, char c)
{
	t_quospl	split;

	if (!s)
		return (NULL);
	split.in_double = 0;
	split.in_single = 0;
	split.word_count = 0;
	split.arr = malloc((wordcount(&split, s, c) + 1) * (sizeof(char *)));
	printf("%d\n", split.word_count);
	if (!split.arr)
		return (NULL);
	ft_quotesplit2(&split, s, c, -1);
	return (split.arr);
}