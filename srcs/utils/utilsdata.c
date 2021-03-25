/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:05 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/25 20:31:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb		get_color(char **rgbtab)
{
	t_rgb		rgb;

	rgb.r = ft_atoi(rgbtab[0]);
	rgb.g = ft_atoi(rgbtab[1]);
	rgb.b = ft_atoi(rgbtab[2]);
	if (rgb.r > 255 || rgb.g > 255 || rgb.b > 255)
		error(ERR_ELEMENT);
	if (rgb.r < 0 || rgb.g < 0 || rgb.b < 0)
		error(ERR_ELEMENT);
	return (rgb);
}

t_vector	get_orientation(char **ori)
{
	t_vector	vector;

	vector.x = ft_atof(ori[0]);
	vector.y = ft_atof(ori[1]);
	vector.z = ft_atof(ori[2]);
	if (vector.x < -1.0 || vector.x > 1.0)
		error(ERR_ELEMENT);
	if (vector.y < -1.0 || vector.y > 1.0)
		error(ERR_ELEMENT);
	if (vector.z < -1.0 || vector.y > 1.0)
		error(ERR_ELEMENT);
	return (vector);
}

t_vector	get_cord(char **cord)
{
	t_vector	vector;

	vector.x = ft_atof(cord[0]);
	vector.y = ft_atof(cord[1]);
	vector.z = ft_atof(cord[2]);
//	free_data(cord);
	return (vector);
}
