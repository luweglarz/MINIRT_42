/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:38:38 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 13:18:19 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	error(int errorcode, t_scene *scene)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (errorcode == ERR_NBFILE)
		write(STDERR_FILENO, "Too much arguments\n", 19);
	if (errorcode == ERR_FEWFILE)
		write(STDERR_FILENO, "Too few arguments\n", 18);
	if (errorcode == ERR_SAVE)
		write(STDERR_FILENO, "3rd argument must be \"-save\"\n", 30);
	if (errorcode == ERR_MALLOC)
		write(STDERR_FILENO, "Malloc failed\n", 14);
	if (errorcode == ERR_ELEMENT)
		write(STDERR_FILENO, "Wrong element value\n", 20);
	ft_lstclear(&scene->sphere, free);
	ft_lstclear(&scene->camera, free);
	ft_lstclear(&scene->square, free);
	ft_lstclear(&scene->plane, free);
	ft_lstclear(&scene->cylinder, free);
	ft_lstclear(&scene->triangle, free);
	ft_lstclear(&scene->light, free);
	exit(errorcode);
}
