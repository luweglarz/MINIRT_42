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

int	sphereintersec(t_ray *ray, t_sphere *sphere, double *t1, double *t2)
{
	t_vector	dist = vec_diff(&ray->origin, &sphere->cord);
	double	A = vec_dot(&ray->dir, &ray->dir);
	double  B = 2 * vec_dot(&ray->dir, &dist);
	double  C = vec_dot(&dist, &dist) - (sphere->radius * sphere->radius);
	double  discriminant = (B * B) - 4 * (A * C);
	if (discriminant < 0)
	{
		*t1 = 2000000.0;
		*t2 = 1.0;
		return (0);
	}
	double	discsqrt = sqrt(discriminant);
	*t1 = (-B + discsqrt) / (2 * A);
	*t2 = (-B - discsqrt) / (2 * A);
	return (1);
}

int	raytosphere(t_ray *ray, t_scene *scene,
	double t_min, double t_max)
{
   	t_list      	*sphere_list;
	t_sphere    	*sphere;
	double		t1;
	double		t2;
	int		closest_sphere;

  	sphere_list = scene->sphere;
	closest_sphere = -1;
    	while(sphere_list->next)
    	{
       		sphere = sphere_list->content;
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
		ray->origin.x = 0.0;
	ray->origin.y = 0.0;
	ray->origin.z = 0.0;
	ray->dir.x = 0.0;
	ray->dir.y = 0.0;
	ray->dir.z = 1.0;

}

t_rgb   trace_ray(t_ray ray, t_scene *scene, double t_min, double t_max)
{
	t_rgb		background;
	t_rgb		obj_color;
	background.r = 0;
	background.g = 0;
	background.b = 0;
	if(raytosphere(&ray, scene, t_min, t_max) == 1)
		return (sphere->color);
	return (background);
}
void     ray_tracer(t_scene *scene)
{
    void        *mlx;
    void        *mlx_win;
    t_img_data  img;
    int    x;
    int    y;
    t_rgb           color;
    t_ray           ray;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, scene->reso.w, scene->reso.h, "MiniRT");
    img.img = mlx_new_image(mlx, scene->reso.w, scene->reso.h);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    x = -scene->reso.w/2;
	y = 0;
    ray_init(&ray);
	printf("le x = %i\n",x );
	printf("le y = %i\n",y );
	printf ("la reso w %i\n", scene->reso.w/2);
	printf ("la reso h %i\n", scene->reso.h/2);
    	while (x < scene->reso.w/2)
		{
			 y = -scene->reso.h/2;
		    while (y < scene->reso.h/2)
		    {
			    ray.dir.x = x * 1920.0 / scene->reso.w;
			    ray.dir.y = y * 1080.0 / scene->reso.h;
			    color = trace_ray(ray, scene, 1.0, 2000000.0);
				my_pixel_put(&img, scene->reso.w / 2 + x,
				scene->reso.h / 2 - y - 1, &color);
			    y++;
			}
			x++;
		}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
