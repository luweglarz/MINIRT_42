/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/21 14:13:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int		main(int argc, char **argv)
{
	t_scene		*scene;
	int		fd;

	if (argc == 1)
		error(ERR_FEWFILE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		scene = parsing_config(fd);
		close(fd);
		ray_tracer(scene);
	}
	if ((argc == 3) && (ft_strcmp(argv[2], "-save") == 0))
	{
		fd = open(argv[1], O_RDONLY);
		scene = parsing_config(fd);
		close(fd);
		create_bmp(scene);
	}
	else if  ((argc == 3) && (ft_strcmp(argv[2], "-save") != 0))
		error(ERR_SAVE);
	if (argc > 3)
		error(ERR_NBFILE);
}
