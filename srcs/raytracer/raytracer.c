/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/12 14:45:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	trace_ray(t_ray ray, t_scene *scene)
{
	raytosphere(&ray, scene);
	raytoplane(&ray, scene);
	raytotriangle(&ray, scene);
	raytosquare(&ray, scene);
	raytocylinder(&ray, scene);
	return (ray.ray_color);
}

void	ray_tracer(t_scene *scene)
{
	t_mlx		mlx_session;
	t_px		px;
	t_rgb		color;
	t_ray		ray;

	px.x = 0;

	init_mlx(&mlx_session, scene);
	while (++px.x < scene->reso.w)
	{
		px.y = 0;
		while (++px.y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, scene, px, &mlx_session);
			color = trace_ray(ray, scene);
			my_pixel_put(&mlx_session.img, px, &color);
		}
	}
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
	mlx_loop(mlx_session.mlx);
}
