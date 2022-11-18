/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:59 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/18 19:55:05 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char *get_next_line(int fd);
char *ft_read(int fd, char *buffer);
size_t	ft_strlen(char *s);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strdup(char *s1);
int	ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char *ft_firstl(char *buff);
char *ft_nextl(char *buff);


#endif