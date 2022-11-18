/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:49:13 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/18 20:00:38 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *buff)
{
	char *str;
	int check;

	if (!buff)
		buff = ft_strdup("");
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	check = 1;
	while (ft_strchr(buff, '\n') == 0 && check != 0)
	{
		check = read(fd, str, BUFFER_SIZE);
		str[check] = '\0';
		buff = ft_strjoin(buff, str);
	}
	return buff;
}

char *ft_firstl(char *buff)
{
	char *line;
	int len;
	int i;

	len = ft_strchr(buff, '\n');
	line = malloc(len + 2);
	if (!line)
		return (0);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *ft_nextl(char *buff)
{
	char *nextl;
	int i;
	int j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	nextl = malloc(ft_strlen(buff) - i + 1);
	if (!nextl)
		return (0);
	j = 0;
	while (buff[i])
		nextl[j++] = buff[++i];
	nextl[j] = '\0';
	return (nextl);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	line = ft_firstl(buffer);
	buffer = ft_nextl(buffer);
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
	 
// 	//printf("%s", get_next_line(fd));
// 	//printf("%s", get_next_line(fd));
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// }