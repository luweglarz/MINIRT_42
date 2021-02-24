/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:56 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/24 22:10:13 by user42           ###   ########.fr       */
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

void	init_mlx(t_mlx *mlx_session, t_scene *scene);

void	ray_tracer(t_scene *scene);
void	ray_init(t_ray *ray);
t_rgb	trace_ray(t_ray ray, t_scene *scene);

t_frgb	compute_light(t_vector ray_pos, t_vector normal, t_scene *scene, void *obj);

void	raytosphere(t_ray *ray, t_scene *scene);
double	sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t);

void	raytoplane(t_ray *ray, t_scene *scene);
double	plane_intersec_equation(t_ray *ray, t_plane *plane);

void	raytotriangle(t_ray *ray, t_scene *scene);
double	triangle_intersec_equation(t_ray *ray, t_triangle *triangle);

void	raytosquare(t_ray *ray, t_scene *scene);
double	square_intersec_equation(t_ray *ray, t_square *square);

void	raytocylinder(t_ray *ray, t_scene *scene);
double	cylinder_intersec_equation(t_ray *ray, t_cylinder *cylinder);

#endif
