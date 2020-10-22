/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/22 13:07:14 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_scene	scene;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		parsing_config(&scene, fd);
		close(fd);
	}
	else
		write(STDERR_FILENO, "error", 5);
}
