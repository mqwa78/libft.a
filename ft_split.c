/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:49:50 by mamahtal          #+#    #+#             */
/*   Updated: 2023/11/11 11:32:39 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_char(char rep, char s)
{
	return (s == rep);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_is_char(c, *s))
			s++;
		if (*s && !ft_is_char(c, *s))
			count++;
		while (*s && !ft_is_char(c, *s))
			s++;
	}
	return (count);
}

static size_t	ft_count_alpha(const char *s, int pos, char c)
{
	size_t	count;

	count = 0;
	while (s[pos] && !ft_is_char(c, s[pos]))
	{
		count++;
		pos++;
	}
	return (count);
}

static char	*ft_dup(const char *s, size_t *pos, char c)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_count_alpha(s, *pos, c);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[*pos] && !ft_is_char(c, s[*pos]))
	{
		str[i] = s[*pos];
		i++;
		*pos += 1;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;

	strs = malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	if (!strs)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_count_words(s, c))
	{
		while (ft_is_char(c, s[j]))
			j++;
		strs[i] = ft_dup(s, &j, c);
		if (!strs[i])
		{
			while (i >= 0)
				free(strs[i--]);
			free(strs);
			return (NULL);
		}
	}
	strs[i] = 0;
	return (strs);
}
