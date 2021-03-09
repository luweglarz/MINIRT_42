/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/09 14:34:39 by user42           ###   ########.fr       */
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
	ray->ray_t = INFINITY;
	ray->obj = NULL;
}

void	init_mlx(t_mlx *mlx_session, t_scene *scene)
{
	int	size_w;
	int	size_h;

	size_w = 0;
	size_h = 0;
	mlx_session->mlx = mlx_init();
	mlx_get_screen_size(mlx_session->mlx, &size_w, &size_h);
	if (scene->reso.w > size_w)
		scene->reso.w = size_w;
	if (scene->reso.h > size_h)
		scene->reso.h = size_h;
	mlx_session->mlx_win =
	mlx_new_window(mlx_session->mlx, scene->reso.w, scene->reso.h, "MiniRT");
	mlx_session->img.img =
	mlx_new_image(mlx_session->mlx, scene->reso.w, scene->reso.h);
	mlx_session->img.addr =
	mlx_get_data_addr(mlx_session->img.img, &mlx_session->img.bpp,
	&mlx_session->img.line_length, &mlx_session->img.endian);
}

t_vector	
set_ray_dir(t_ray *ray, t_scene scene, t_camera camera, t_px px)
{
	double	 	aspect_ratio;
	double	 	fov;

	fov = tan((double)camera.fov / 2 * PI / 180);
	aspect_ratio = scene.reso.w / scene.reso.h;
	ray->dir.x = (2 * (px.x + 0.5) / scene.reso.w - 1) * aspect_ratio * fov * aspect_ratio;
	ray->dir.y = (1 - 2 * (px.y + 0.5) / scene.reso.h) * fov;
	ray->dir = vec_diff(ray->dir, ray->origin);
	ray->dir = normalize(ray->dir);
	return (ray->dir);
}

void	init_camera(t_ray *ray, t_scene *scene, t_px px)
{
	t_list	 	*camera_list;
	t_camera 	*camera;

	//double		matrix[4][4];

	camera_list = scene->camera;
	camera = camera_list->content;
	ray->origin.x = camera->cord.x;
	ray->origin.y = camera->cord.y;
	ray->origin.z = camera->cord.z;
	ray->dir = set_ray_dir(ray, *scene, *camera, px);
}
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

	px.x = -1;

	init_mlx(&mlx_session, scene);
	while (++px.x < scene->reso.w)
	{
		px.y = -1;
		while (++px.y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, scene, px);
			color = trace_ray(ray, scene);
			my_pixel_put(&mlx_session.img, px, &color);
		}
	}
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
	mlx_loop(mlx_session.mlx);
}
