/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:47:39 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/12 13:47:57 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

/*size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] && i < (int)size)
		i++;
	j = i;
	while (src[i - j] && i < (int)size - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < (int)size)
		dest[i] = 0;
	return (j + ft_strlen(src));
}*/

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(d);
	index = 0;
	while (d[index])
		index++;
	i = 0;
	while (s[i] && (i + index + 1) < (dstsize))
	{
		d[index + i] = s[i];
		i++;
	}
	if (i < dstsize)
		d[index + i] = '\0';
	if (dstsize <= dst_len)
		return (ft_strlen(s) + dstsize);
	else
		return (ft_strlen(s) + dst_len);
}

/*int	main(void)
{	
	char	dest[30]; memset(dest, 0, 30);
	char	*src = (char *)"AAAAAAAAA";
	char	d[30]; memset(d, 0, 30);
	char	*s = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	d[0] = 'B';
	printf("%d\n", ft_strlcat(dest, src, -1) == strlen(src));
	printf("%s\n", dest);
	printf("%d\n", strlcat(d, s, -1) == strlen(src));
	printf("%s\n", d);
	//printf("%d\n", strcmp(dest, "B"));
	return (0);
}*/