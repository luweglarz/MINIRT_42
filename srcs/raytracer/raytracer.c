/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/01/14 15:20:56 by lweglarz         ###   ########.fr       */
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

t_rgb	trace_ray(t_ray ray, t_scene *scene)
{
	t_rgb	background;
	t_rgb	obj_color;

	background.r = 0;
	background.g = 0;
	background.b = 0;
	ray.dir.x = x * 1920.0 / scene->reso.w;
	ray.dir.y = y * 1080.0 / scene->reso.h;
	if (raytosphere(&ray, scene, &obj_color) == 1)
		return (obj_color);
	return (background);
}

void	init_mlx(t_mlx *mlx_session)
{
	mlx_session->mlx = mlx_init;
	mlx_session->mlx_win =
	mlx_new_window(mlx, scene->reso.w, scene->reso.h, "MiniRT");
	mlx_session->img.img =
	mlx_new_image(mlx, scene->reso.w, scene->reso.h);
	mlx_session->img.addr =
	mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
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
	init_mlx(&mlx_session);
	ray_init(&ray);
	while (x < scene->reso.w / 2)
	{
		y = -scene->reso.h / 2;
		while (y < scene->reso.h / 2)
		{
			color = trace_ray(ray, scene);
			my_pixel_put(&img, scene->reso.w / 2 + x,
			scene->reso.h / 2 - y - 1, &color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
	mlx_loop(mlx);
}
