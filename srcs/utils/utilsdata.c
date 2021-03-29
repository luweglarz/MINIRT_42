/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:05 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/26 18:55:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb		get_color(char **rgbtab, t_scene *scene, char **data, void *elm)
{
	t_rgb		rgb;

	if (rgbtab[0] == NULL || rgbtab[1] == NULL || rgbtab[2] == NULL)
	{
		free(elm);
		free_data(data);
		free_data(rgbtab);
		error(ERR_ELEMENT_FORMAT, scene);
	}
	rgb.r = ft_atoi(rgbtab[0]);
	rgb.g = ft_atoi(rgbtab[1]);
	rgb.b = ft_atoi(rgbtab[2]);
	if (rgb.r > 255 || rgb.g > 255 || rgb.b > 255 ||
	rgb.r < 0 || rgb.g < 0 || rgb.b < 0)
	{
		free(elm);
		free_data(data);
		free_data(rgbtab);
		error(ERR_ELEMENT, scene);
	}
	free_data(rgbtab);
	return (rgb);
}

t_vector	get_orientation(char **ori, t_scene *scene, char **data, void *elm)
{
	t_vector	vector;

	if (ori[0] == NULL || ori[1] == NULL || ori[2] == NULL)
	{
		free(elm);
		free_data(data);
		free_data(ori);
		error(ERR_ELEMENT_FORMAT, scene);
	}
	vector.x = ft_atof(ori[0]);
	vector.y = ft_atof(ori[1]);
	vector.z = ft_atof(ori[2]);
	if (vector.x < -1.0 || vector.x > 1.0 || vector.y < -1.0 || vector.y > 1.0
	|| vector.z < -1.0 || vector.z > 1.0)
	{
		free(elm);
		free_data(data);
		free_data(ori);
		error(ERR_ELEMENT, scene);
	}
	free_data(ori);
	return (vector);
}

t_vector	get_cord(char **cord, t_scene *scene, char **data, void *elm)
{
	t_vector	vector;

	if (cord[0] == NULL || cord[1] == NULL || cord[2] == NULL)
	{
		free(elm);
		free_data(data);
		free_data(cord);
		error(ERR_ELEMENT_FORMAT, scene);
	}
	vector.x = ft_atof(cord[0]);
	vector.y = ft_atof(cord[1]);
	vector.z = ft_atof(cord[2]);
	free_data(cord);
	return (vector);
}
