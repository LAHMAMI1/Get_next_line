/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:49:11 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/20 15:06:57 by olahmami         ###   ########.fr       */
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

char	*ft_strdup(char *s1)
{
	char	*str;
	int i;
	i= 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i]=s1[i];
		i++;
	}
	str[i]=0;
	return (str);
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
	if ((char)c == 0)
		return (i);
	return (0);
}
int	ft_strlen_n(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i]&&s[i]!=c)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*p;
	int i;

	i=0;
	s1len = ft_strlen_n(s1,0);
	s2len = ft_strlen_n(s2,0);
	p = (char *)malloc(s1len + s2len + 1);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i]=s1[i];
		i++;
	}
	while (*s2)
	{
		p[i]=*s2++;
		i++;
	}
	p[i]=0;
	free(s1);
	return (p);
}
