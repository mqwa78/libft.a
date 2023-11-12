/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:49:50 by mamahtal          #+#    #+#             */
/*   Updated: 2023/11/12 13:48:02 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	ft_is_char(char rep, char s)
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
	int	n;

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
		n = i;
		if (!strs[i])
		{
			while (n >= 0)
				free(strs[n--]);
			free(strs);
			return (NULL);
		}
	}
	strs[i] = 0;
	return (strs);
}*/

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

static void	set_mem(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		count = 0;
		while (s[index + count] && s[index + count] != c)
			count++;
		if (count > 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return ;
			fill_tab(tab[i], (s + index), c);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	set_mem(tab, s, c);
	return (tab);
}

/*int	main(void)
{
	char	**tab;
	char	*str;
	size_t	i;

	str = "";
	tab = ft_split(str, ' ');
	i = 0;
	while (i < count_words(str, ' '))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
