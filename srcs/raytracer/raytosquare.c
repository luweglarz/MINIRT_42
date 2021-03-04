/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:58:49 by user42            #+#    #+#             */
/*   Updated: 2021/03/02 16:46:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	square_intersec_equation(t_ray *ray, t_square *square)
{
	(void)ray;
	(void)square;
	return 1;
}

void	square_intersec_color(t_square *square, t_ray *ray, t_scene *scene)
{
	t_vector		ray_pos;
	t_vector		normal;
	double			t_;

	t_ = square_intersec_equation(ray, square);
	if (t_ < INFINITY && t_ > 1 && t_ < ray->ray_t)
	{
		ray->ray_t = t_;
		ray->obj = square;
		ray->ray_color = square->color;
				(void)ray_pos;
		(void)scene;
		(void)normal;
		//ray->ray_color = color_multipli(color_range1(ray->ray_color),
		//compute_light(ray_pos, normal, scene, ray->obj));	
	}
}

void		raytosquare(t_ray *ray, t_scene *scene)
{
	t_list			*square_list;
	t_square			*square;


	square_list = scene->square;
	while (square_list->next)
	{
		square = square_list->content;
		square_intersec_color(square, ray, scene);
		square_list = square_list->next;
	}
}