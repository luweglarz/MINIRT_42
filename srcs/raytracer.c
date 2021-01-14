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

#include "../includes/minirt.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}


void	sphereintersec(t_ray *ray, t_sphere *sph, double *t1, double *t2)
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
		return ;
	}
	double	discsqrt = sqrt(discriminant);
	*t1 = (-B + discsqrt) / (2 * A);
	*t2 = (-B - discsqrt) / (2 * A);
}

void    raytosphere(t_ray ray, t_scene *scene, int t_min, int t_max)
{
    t_list      *sphere_list;
    t_sphere    *sphere;

    sphere_list = scene->sphere;
    while(sphere_list->next)
    {
        sphere = sphere_list->content;
        // itere intersec sphere a tout les sphere

    }
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

t_rgb   trace_ray()
{
    //grace au intersection et le .rt on va detecter quel ray lancer

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
			    color = trace_ray(ray, scene, 1, 2000000); // function qui va servir de lancer ray par rapport object du .rt
			    my_pixel_put(&img, scene->reso.w/2 + x, scene->reso.h/2 - y - 1, &color);
                y++;
		    }
            x++;
    	}
}