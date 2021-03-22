/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/22 16:43:37 by user42           ###   ########.fr       */
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

void	the_ray(t_scene *scene, t_camera *camera, t_mlx mlx_session)
{
	t_px		px;
	t_rgb		color;
	t_ray		ray;
	
	px.x = 0;
	while (++px.x < scene->reso.w)
	{
		px.y = 0;
		while (++px.y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, camera, px, scene);
			color = trace_ray(ray, mlx_session.scene);
			my_pixel_put(&mlx_session.img, px, &color);
		}
	}
}

int		cam_hook(int keycode, t_mlx *mlx_session)
{
	t_camera	*camera;

	if (keycode == 100 && mlx_session->nb_cam > 2 && mlx_session->camera_list->next)
	{
		mlx_session->camera_list = mlx_session->camera_list->next;
		camera = mlx_session->camera_list->content;
		if (camera == NULL)
		{
			mlx_session->camera_list = mlx_session->camera_list->prev;
			return (0);
		}
		the_ray(mlx_session->scene, camera, *mlx_session);
			mlx_put_image_to_window(mlx_session->mlx,
	mlx_session->mlx_win, mlx_session->img.img, 0, 0);
	}
	if (keycode == 97 && mlx_session->nb_cam > 2 && mlx_session->camera_list->prev)
	{
		mlx_session->camera_list = mlx_session->camera_list->prev;
		camera = mlx_session->camera_list->content;
		the_ray(mlx_session->scene, camera, *mlx_session);
			mlx_put_image_to_window(mlx_session->mlx,
	mlx_session->mlx_win, mlx_session->img.img, 0, 0);
	}
	return (0);
}

void	ray_tracer(t_scene *scene, int save)
{
	t_mlx		mlx_session;
	t_camera	*camera;
	t_list	 	*camera_list;

	camera_list = scene->camera;
	camera = camera_list->content;
	mlx_session.camera_list = camera_list;
	mlx_session.nb_cam = lstsize(&mlx_session.camera_list);
	mlx_session.scene = scene;
	init_mlx_image(&mlx_session, scene);
	the_ray(scene, camera, mlx_session);
	if ( save == 1)
		create_bmp(scene, &mlx_session);
	init_mlx_window(&mlx_session, scene);
	mlx_key_hook(mlx_session.mlx_win,  key_code, &mlx_session);
	mlx_hook(mlx_session.mlx_win, 33, 1L << 17, close_window, &mlx_session);
	mlx_hook(mlx_session.mlx_win, 9, 1L << 21, refresh_window, &mlx_session);
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
	mlx_loop(mlx_session.mlx);
}
