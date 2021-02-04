/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/04 15:27:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ray_init(t_ray *ray)
{
	ray->origin.x = 0.0;
	ray->origin.y = 0.0;
	ray->origin.z = 0.0;
	ray->dir.x = 0.0;
	ray->dir.y = 0.0;
	ray->dir.z = 1.0;
}

t_rgb	trace_ray(t_ray ray, t_scene *scene, int x, int y)
{
	t_rgb	obj_color;
	t_rgb	background;

	background.r = 0;
	background.g = 0;
	background.b = 0;
	ray.dir.x = x * 1.0 / scene->reso.w;
	ray.dir.y = y * 1.0 / scene->reso.h;
	if (raytosphere(&ray, scene, &obj_color) == 1)
		return (obj_color);
	return (background);
}

void	init_mlx(t_mlx *mlx_session, t_scene *scene)
{
	mlx_session->mlx = mlx_init();
	mlx_session->mlx_win =
	mlx_new_window(mlx_session->mlx, scene->reso.w, scene->reso.h, "MiniRT");
	mlx_session->img.img =
	mlx_new_image(mlx_session->mlx, scene->reso.w, scene->reso.h);
	mlx_session->img.addr =
	mlx_get_data_addr(mlx_session->img.img, &mlx_session->img.bpp,
	&mlx_session->img.line_length, &mlx_session->img.endian);
}

void	ray_tracer(t_scene *scene)
{
	t_mlx		mlx_session;
	int			x;
	int			y;
	t_rgb		color;
	t_ray		ray;

	x = -scene->reso.w / 2;
	y = 0;
	init_mlx(&mlx_session, scene);
	ray_init(&ray);
	while (++x < scene->reso.w / 2)
	{
		y = -scene->reso.h / 2;
		while (++y < scene->reso.h / 2)
		{
			color = trace_ray(ray, scene, x, y);
			my_pixel_put(&mlx_session.img, scene->reso.w / 2 + x,
			scene->reso.h / 2 - y - 1, &color);
		}
	}
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
	mlx_loop(mlx_session.mlx);
}
