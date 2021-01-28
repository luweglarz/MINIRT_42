/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytosphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:48:11 by lweglarz          #+#    #+#             */
/*   Updated: 2021/01/19 15:48:14 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void		sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t)
{
	t_vector	dist;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	dist = vec_diff(ray->origin, sphere->cord);
	a = vec_dot(ray->dir, ray->dir);
	b = 2 * vec_dot(ray->dir, dist);
	c = vec_dot(dist, dist) - (sphere->radius * sphere->radius);
	discriminant = (b * b) - 4 * (a * c);
	if (discriminant < 0)
	{
		t[0] = INFINITY;
		t[1] = 1.0;
		return ;
	}
	t[0] = (-b + sqrt(discriminant)) / (2 * a);
	t[1] = (-b - sqrt(discriminant)) / (2 * a);
}

double	compute_light(t_ray *ray, t_vector normal, t_scene *scene)
{
	double i;
	double normal_dot;
	t_vector L;
	t_list	*lights;
	t_light	*light;
	//(void)ray;
	//(void)normal;
	i = 0.0;
	lights = scene->light;
	while (lights->next)
	{

		light = lights->content;
		i += scene->amli.ratio;
		L = vec_diff(light->cord, ray->dir);
		normal_dot = vec_dot(normal, L);
		if (normal_dot > 0)
			i += light->ratio * normal_dot / vec_length(normal) * vec_length(L);
		lights = lights->next;
	}
	//printf("%f\n", i);
	return (i);
}


void	sphere_intersec_t(double *t, double *ray_t, t_sphere *sphere, t_rgb *obj_color)
{
	if (t[0] > 1.0 && t[0] < INFINITY && t[0] < *ray_t)
	{
		*ray_t = t[0];
		*obj_color = sphere->color;
	}
	if (t[1] > 1.0 && t[1] < INFINITY && t[1] < *ray_t)
	{
		*ray_t = t[1];
		 *obj_color = sphere->color;
	}
}

t_vector	ray_equation(t_ray *ray, double ray_t)
{
	t_vector	equa_ray;
	equa_ray = vec_add(ray->origin, vec_multipli_coeff(ray->dir, ray_t));
	return(equa_ray);
}

int		raytosphere(t_ray *ray, t_scene *scene, t_rgb *obj_color)// mettre variable obj color dans struct scen ??
{
	t_list			*sphere_list;
	t_sphere		*sphere;
	double			t[2];
	double			ray_t;
	t_vector		normal;

	sphere_list = scene->sphere;
	ray_t = INFINITY;
	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	while (sphere_list->next)
	{
		sphere = sphere_list->content;
		sphere_intersec_equation(ray, sphere, t);
		sphere_intersec_t(t, &ray_t, sphere, obj_color);
		normal = vec_diff(ray_equation(ray, ray_t), sphere->cord);
		normal = vec_div(normal, vec_length(normal));
		if (ray_t != INFINITY)
			*obj_color = rgb_multipli(obj_color,compute_light(ray, normal, scene));
		sphere_list = sphere_list->next;
	}
	if (ray_t == INFINITY)
		return (0);
	return (1);
}
