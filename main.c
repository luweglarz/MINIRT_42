/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/27 16:14:48 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int		main(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;

	if (argc == 1)
		write(STDERR_FILENO, "error", 5);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		scene = parsing_config(fd);
		close(fd);
	}
	else if (argc == 3 && ft_strncmp(argv[2], "-save", 5) == 0)
		write(1, "screenshot", 11);
	else if (argc > 3)
		write(STDERR_FILENO, "error", 5);
}
