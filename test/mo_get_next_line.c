/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:17:32 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/18 20:01:59 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
char *ft_rest(char *buff)
{
	char *str;
	int i;
	int j = 0;
	
	i=0;
	while (buff[i]&&buff[i]!='\n')
		i++;
	
	str= malloc(ft_strlen(buff) - i +1);
	if(!str)
		return NULL;
	while(buff[i])
		str[j++]=buff[++i];
	str[j]=0;
	// free(buff);
	// buff =NULL;
	return str;
}
char *ft_firstline(char *buff)
{
	char *str;
	int i;
	int len = ft_strchr(buff, '\n');
	i = 0;
	str = malloc(len + 2);
	if(!str)
		return 0;
	//ft_strncpy(str,buff,len+1);
	while (buff[i]&&buff[i]!='\n')
	{
	str[i]=buff[i];	
		i++;
	}
	if(buff[i] == '\n')
	{
		str[i]=buff[i];
		i++;
	}
	str[i]=0;
	return str;
}
char *ft_read(int fd, char *buff)
{
	char *str;
	int check;

	check = 1;
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	if (!buff)
		buff = calloc(1,1);
	while (!ft_strchr(buff, '\n')  && check != 0)
	{
		check = read(fd, str, BUFFER_SIZE);
		if(check<0)
		{
			free(str);
			free(buff);
			str=NULL;
			buff=NULL;
			return NULL;
		}
		str[check] = 0;
		buff = ft_strjoin(buff, str);
		if(!buff||!*buff)
		{
			buff = NULL ;
			break;
		}
			
	}
	free(str);
	str=NULL;
	return buff;
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *str;
	if(fd<0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = ft_read(fd, buffer);
	if(!buffer||!*buffer){
		free(buffer);
		buffer= NULL;
		return NULL;
	}	
	str = ft_firstline(buffer);
	buffer = ft_rest(buffer);
	return str;
}
