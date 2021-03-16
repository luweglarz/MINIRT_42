/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:20:54 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/16 20:58:50 by user42           ###   ########.fr       */
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
	init_mlx_image(&mlx_session, scene);
	printf("camera x: %f\n y: %f\n z: %f\n", camera->cord.x, camera->cord.y, camera->cord.z);
	while (++px.x < scene->reso.w)
	{
		px.y = 0;
		while (++px.y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, camera, px, scene);
			//printf("color1 r: %d\n g: %d\n b: %d\n", color.r, color.g, color.b);
			color = trace_ray(ray, mlx_session.scene);
			//printf("color1 r: %d\n g: %d\n b: %d\n", color.r, color.g, color.b);
			my_pixel_put(&mlx_session.img, px, &color);
			//printf("color2 r: %d\n g: %d\n b: %d\n", color.r, color.g, color.b);
		}
	}
	mlx_put_image_to_window(mlx_session.mlx,
	mlx_session.mlx_win, mlx_session.img.img, 0, 0);
}

int			lstsize(t_list **head)
{
	t_list		*cursor;
	int			count;

	count = 0;
	cursor = *head;
	while (cursor)
	{
		cursor = cursor->next;
		count++;
	}
	return (count);
}

int		cam_hook(int keycode, t_mlx *mlx_session)
{
	t_camera	*camera;
	t_list	 	*camera_list;
	int			move;

	move = 0;
	camera_list = mlx_session->scene->camera;
	camera_list = camera_list->next;
	printf("size %d\n", lstsize(&camera_list));
	if (keycode == 100 && lstsize(&camera_list) > 1)
	{
		printf("test100\n");
		//mlx_destroy_image(mlx_session->mlx_win, mlx_session->img.img);
		camera_list = camera_list->next;
	}
	if (keycode == 97 && lstsize(&camera_list) > 1)
	{
		//mlx_destroy_image(mlx_session->mlx_win, mlx_session->img.img);
		printf("test97\n");
		camera_list = camera_list->prev;
	}
	camera = camera_list->content;
	the_ray(mlx_session->scene, camera, *mlx_session);
	return (0);
}

void	ray_tracer(t_scene *scene)
{
	t_mlx		mlx_session;
	t_camera	*camera;
	t_list	 	*camera_list;

	camera_list = scene->camera;
	camera_list = camera_list->next;
	camera = camera_list->content;
	mlx_session.scene = scene;
	init_mlx_window(&mlx_session, scene);
	keys(mlx_session);
	the_ray(scene, camera, mlx_session);
	mlx_loop(mlx_session.mlx);
}
