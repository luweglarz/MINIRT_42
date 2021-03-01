/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/02/27 00:01:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	get_intensity(t_scene scene, t_vector light_dir, t_vector normal, t_light light)
{
	double		intensity;
	double		cos;

	intensity = 0.0;
	intensity = scene.amli.ratio;
	cos = vec_dot(normal, light_dir);
	if (cos > 0)
		intensity += light.ratio * cos;
	return (intensity);
}


int	sphere_intersec(t_scene scene, t_ray *ray, double length)
{
	double			t[2];
	t_list			*sphere_list;
	t_sphere		*sphere;
	double	t_;
	sphere_list = scene.sphere;
	t_sphere *test;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		t_ = sphere_intersec_equation(ray, sphere, t);
		//printf("t_1 %f\n", t_);
		if (t_ > 0.0001 && t_ < length && t_ < ray->ray_t)
		{
		//	printf("t_2 %f\n", t_);
			ray->ray_t = t_;
			ray->obj = sphere;
			test = ray->obj;
		//	printf("sphere x: %f\n", test->cord.z);
		}
		sphere_list = sphere_list->next;
	}
//	t_sphere *test;
//	if (ray->obj != NULL){
	//test = ray->obj;
	//if (t_ != INFINITY){
//	printf("t_ %f\n", t_);
	//test = ray->obj;
	//printf("sphere x: %f\n", test->cord.z);
	//}
	//printf("sphere x: %f\n", test->cord.z);
	//}
	if (ray->ray_t != INFINITY)
		return (1);
	return (0);
}

int		is_intersection(t_scene scene, t_vector ray_pos, t_vector light_cord, void *obj)
{
	t_ray	ray;

	ray_init(&ray);
	ray.origin = ray_pos;
	ray.dir = vec_diff(light_cord, ray_pos);
	double		length = vec_length(ray.dir);
	if (length > 3)
	{
	printf("ray.dir\n x: %f\n y: %f\n z: %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
	printf("length %f\n", length);
	}
	if (sphere_intersec(scene, &ray, length) && ray.obj != obj)
		return (1);
	return (0);
}

t_frgb	compute_light(t_vector ray_pos, t_vector normal, t_scene *scene, void *obj)
{
	double		intensity;
	t_rgb		light_color;
	t_list		*lights;
	t_light		*light;
	t_vector	light_dir;

	color_init(&light_color);
	lights = scene->light;
	while (lights->next)
	{
		light = lights->content;
		light_dir = vec_diff(light->cord, ray_pos);
		(void)obj;
		if (is_intersection(*scene, ray_pos, light->cord, obj))
		{
			color_init(&light_color);
			break;
		}
		intensity = get_intensity(*scene, light_dir, normal, *light);
		light_color = rgb_add(light_color,
		rgb_multipli(light->color, intensity));
		lights = lights->next;
	}
	light_color = rgb_add(light_color,
	rgb_multipli(scene->amli.color, scene->amli.ratio));
	return (color_range1(light_color));
}
