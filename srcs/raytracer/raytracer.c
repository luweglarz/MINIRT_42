/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/08 16:29:49 by user42           ###   ########.fr       */
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
	mlx_session->mlx = mlx_init();
	mlx_session->mlx_win =
	mlx_new_window(mlx_session->mlx, scene->reso.w, scene->reso.h, "MiniRT");
	mlx_session->img.img =
	mlx_new_image(mlx_session->mlx, scene->reso.w, scene->reso.h);
	mlx_session->img.addr =
	mlx_get_data_addr(mlx_session->img.img, &mlx_session->img.bpp,
	&mlx_session->img.line_length, &mlx_session->img.endian);
}
#define M_PI       3.14159265358979323846
void	init_camera(t_ray *ray, t_scene *scene, int x, int y, t_mlx mlx_session)
{
	t_list	 *camera_list;
	t_camera *camera;
	double	 aspect_ratio;

	(void)mlx_session;
	aspect_ratio = 1;
	camera_list = scene->camera;
	camera = camera_list->content;
	ray->origin.x = camera->cord.x;
	ray->origin.y = camera->cord.y;
	ray->origin.z = camera->cord.z;
//	printf("x: %d\n y: %d\n",x, y);
	if(scene->reso.w > scene->reso.h)
		aspect_ratio = scene->reso.w / scene->reso.h;
	ray->dir.x = (x + 0.5) / scene->reso.w;
	ray->dir.y = (y + 0.5) / scene->reso.h;
	ray->dir.x = (2 * ray->dir.x - 1) * aspect_ratio;
	ray->dir.y = (1 - 2 * ray->dir.y);
	ray->dir.x = ray->dir.x * tan(camera->fov / 2 * M_PI / 180) * aspect_ratio;
	ray->dir.y = ray->dir.y * tan(camera->fov / 2 * M_PI / 180);
	ray->dir = vec_diff(ray->dir, ray->origin);
	ray->dir = normalize(ray->dir);
//	printf("ray->dir\n x: %f\n y: %f\n z: %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
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
	int			x;
	int			y;
	t_rgb		color;
	t_ray		ray;

	x = -1;

	init_mlx(&mlx_session, scene);
	while (++x < scene->reso.w)
	{
		y = -1;
		while (++y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, scene, x, y, mlx_session);
			color = trace_ray(ray, scene);
			my_pixel_put(&mlx_session.img, x, y, &color);
		}
	}
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
	mlx_loop(mlx_session.mlx);
}
