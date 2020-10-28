/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:05 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 13:23:49 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb		*get_color(char **rgbtab)
{
	t_rgb		*rgb;

	if (!(rgb = malloc(sizeof(t_rgb))))
		error(ERR_MALLOC);
	rgb->r = ft_atoi(rgbtab[0]);
	rgb->g = ft_atoi(rgbtab[1]);
	rgb->b = ft_atoi(rgbtab[2]);
	if (rgb->r > 255 || rgb->g > 255 || rgb->b > 255)
		error(ERR_ELEMENT);
	if (rgb->r < 0 || rgb->g < 0 || rgb->b < 0)
		error(ERR_ELEMENT);
	return (rgb);
}

t_vector	*get_orientation(char **ori)
{
	t_vector	*vector;

	if (!(vector = malloc(sizeof(t_vector))))
		error(ERR_MALLOC);
	vector->x = ft_atof(ori[0]);
	vector->y = ft_atof(ori[1]);
	vector->z = ft_atof(ori[2]);
	if (vector->x < -1.0 || vector->x > 1.0)
		error(ERR_ELEMENT);
	if (vector->y < -1.0 || vector->y > 1.0)
		error(ERR_ELEMENT);
	if (vector->z < -1.0 || vector->y > 1.0)
		error(ERR_ELEMENT);
	return (vector);
}

t_vector	*get_cord(char **cord)
{
	t_vector	*vector;

	if (!(vector = malloc(sizeof(t_vector))))
		error(ERR_MALLOC);
	vector->x = ft_atof(cord[0]);
	vector->y = ft_atof(cord[1]);
	vector->z = ft_atof(cord[2]);
	return (vector);
}
