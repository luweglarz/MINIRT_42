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

int	sphereintersec(t_ray *ray, t_sphere *sph, double *t1, double *t2)
{
	t_vector	dist = vec_diff(&ray->origin, &sph->cord);
	double	A = vec_dot(&ray->dir, &ray->dir);
	double  B = 2 * vec_dot(&ray->dir, &dist);
	double  C = vec_dot(&dist, &dist) - (sph->radius * sph->radius);
	double  discriminant = (B * B) - 4 * (A * C);

	if (discriminant < 0)
	{
		*t1 = 2000000;
		*t2 = 1;
		return (0);
	}
	double	discsqrt = sqrt(discriminant);
	*t1 = (-B + discsqrt) / (2 * A);
	*t2 = (-B - discsqrt) / (2 * A);
	return (1);
}

int    raytosphere(t_ray *ray, t_scene *scene, double t_min, double t_max)
{
    t_list      *sphere_list;
	t_sphere	*sphere;
	double		t1;
	double		t2;
	int			closest_sphere;

    sphere_list = scene->sphere;
	sphere = sphere_list->content;
	closest_sphere = -1;
    while(sphere_list->next)
    {
        sphere_list = sphere_list->content;
		sphereintersec(ray, sphere, &t1, &t2);
		if (t1 > t_min && t1 < t_max)
			closest_sphere = 1;
		if (t2 > t_min && t1 < t_max)
			closest_sphere = 1;
		sphere_list = sphere_list->next;
    }
	if (closest_sphere == -1)
		return (0); //pas d'intersec de sphere
	return (1); // intersec de sphere
} 

void    ray_init(t_ray *ray)
{
    ray->origin.x = 0;
	ray->origin.y = 0;
	ray->origin.z = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 1;
}

t_rgb   trace_ray(t_ray ray, t_scene *scene, double t_min, double t_max)
{
	t_sphere	*sphere;
	t_rgb		background;

	background.r = 0;
	background.g = 0;
	background.b = 0;
	sphere = scene->sphere->content;
	if	(raytosphere(&ray, scene, t_min, t_max) == 1)
		return (sphere->color);
    //grace au intersection et le .rt on va detecter quel ray lancer
 //   if  (raytosphere(&ray, &scene, t_min, t_max) == 1)
        //return (//color de la sphere);
	return (background);
}
void     ray_tracer(t_scene *scene)
{
    void        *mlx;
    void        *mlx_win;
    t_img_data  img;
    unsigned int    x;
    unsigned int    y;
    t_rgb           color;
    t_ray           ray;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, scene->reso.w, scene->reso.h, "MiniRT");
    img.img = mlx_new_image(mlx, scene->reso.w, scene->reso.h);
    x = -scene->reso.w/2;
    y = -scene->reso.h/2;
    ray_init(&ray);
    	while (x < scene->reso.w/2)
	    {
		    while (y < scene->reso.h/2)
		    {
			    ray.dir.x = x * 1.0 / scene->reso.w;
			    ray.dir.y = y * 1.0 / scene->reso.h;
			    color = trace_ray(ray, scene, 1.0, 2000000.0); // function qui va servir de lancer ray par rapport object du .rt
			    my_pixel_put(&img, scene->reso.w/2 + x, scene->reso.h/2 - y - 1, &color);
                y++;
		    }
            x++;
    	}
}