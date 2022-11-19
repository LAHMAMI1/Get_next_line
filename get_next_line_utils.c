/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:49:11 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/19 20:23:56 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	if (src == dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*str;

	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	return (ft_strncpy(str, s1, ft_strlen(s1) + 1));
}

int	ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*p;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = (char *)malloc(s1len + s2len + 1);
	if (!p)
		return (0);
	else
	{
		ft_strncpy(p, s1, s1len);
		ft_strncpy(p + s1len, s2, s2len + 1);
	}
	free(s1);
	return (p);
}