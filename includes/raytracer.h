/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:56 by lweglarz          #+#    #+#             */
/*   Updated: 2021/01/19 15:54:56 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "minirt.h"

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
}				t_mlx;

void		sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t);
void	sphere_intersec_t(double *t, double *ray_t, t_sphere *sphere, t_rgb *obj_color);
int		raytosphere(t_ray *ray, t_scene *scene, t_rgb *obj_color);
void	ray_init(t_ray *ray);
void	init_mlx(t_mlx *mlx_session, t_scene *scene);
t_rgb	trace_ray(t_ray ray, t_scene *scene, int x, int y);
void	ray_tracer(t_scene *scene);
double	compute_light(t_ray *ray, t_vector normal, t_scene *scene);
#endif
