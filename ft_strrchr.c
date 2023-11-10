/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:39:13 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/10 13:52:14 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	(unsigned char)c;
	len = ft_strlen(s) + 1;
	while ((int)len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}