/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:34:54 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/14 13:06:46 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 128

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
int		ft_strlenc(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	ft_bzero(void *s, size_t n);

#endif
