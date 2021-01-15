/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 12:24:36 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int		main(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;

	if (argc == 1)
		error(ERR_FEWFILE);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		scene = parsing_config(fd);
		ray_tracer(scene);
		close(fd);
	}
	if ((argc == 3) && (ft_strcmp(argv[2], "-save") == 0))
		write(1, "screenshot", 11);
	else if  ((argc == 3) && (ft_strcmp(argv[2], "-save") != 0))
		error(ERR_SAVE);
	if (argc > 3)
		error(ERR_NBFILE);
}
