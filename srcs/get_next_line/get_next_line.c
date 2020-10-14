/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:17:29 by lweglarz          #+#    #+#             */
/*   Updated: 2020/09/08 15:42:01 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*joinnfree(char *tmp, char *buffer)
{
	char			*tmp_buff;

	if (tmp)
	{
		tmp_buff = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		tmp = ft_strdup(tmp_buff);
		free(tmp_buff);
		tmp_buff = NULL;
	}
	else
		tmp = ft_strdup(buffer);
	return (tmp);
}

char		*savenfree(char *tmp, int line_n, int line_z)
{
	char	*save;

	if (tmp)
	{
		save = ft_substr(tmp, line_n + 1, line_z);
		free(tmp);
		tmp = NULL;
		tmp = ft_strdup(save);
		free(save);
		save = NULL;
	}
	return (tmp);
}

int			free_error(int ret, char **tmp)
{
	if (ret <= 0 && tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (ret);
}

int			read_line(char **tmp, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_size;

	ft_bzero(buff, BUFFER_SIZE + 1);
	while ((read_size = read(fd, buff, BUFFER_SIZE)))
	{
		if (read_size == -1)
			return (-1);
		buff[read_size] = '\0';
		*tmp = joinnfree(*tmp, buff);
		if (ft_strlenc(*tmp, '\n') == -1 && read_size == 0)
			return (0);
		if (ft_strlenc(*tmp, '\n') != -1)
			return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*tmp;
	int				ret;
	int				line_n;
	int				line_z;

	ret = 1;
	if (!tmp || ft_strlenc(tmp, '\n') == -1)
	{
		if (!tmp)
			tmp = ft_strdup("");
		if ((ret = read_line(&tmp, fd)) == -1)
			return (free_error(ret, &tmp));
	}
	line_n = ft_strlenc(tmp, '\n');
	line_z = ft_strlenc(tmp, '\0');
	if (ret != 0)
		*line = ft_substr(tmp, 0, line_n);
	else
		*line = ft_strdup(tmp);
	tmp = savenfree(tmp, line_n, line_z);
	return (free_error(ret, &tmp));
}
