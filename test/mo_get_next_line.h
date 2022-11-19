/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:17:41 by olahmami          #+#    #+#             */
/*   Updated: 2022/11/18 13:28:02 by olahmami         ###   ########.fr       */
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
char	*ft_strjoin(char  *s1, char  *s2);
int ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif