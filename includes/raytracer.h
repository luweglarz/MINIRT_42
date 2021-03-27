/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:56 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/27 21:07:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "minirt.h"

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
	double		ray_t;
	t_vector	ray_n_t;
	t_rgb		ray_color;
	void		*obj;
}				t_ray;

t_vector		ray_equation(t_ray *ray, double ray_t);

void			ray_init(t_ray *ray);
void			ray_tracer(t_scene scene, int save);
void			the_ray(t_scene scene, t_camera *camera, t_mlx mlx_session);
void			set_camera_pos(t_ray *ray, t_camera *camera, t_px px,
t_scene scene);
void			cam_hook(int keycode, t_mlx *mlx_session);

t_frgb			compute_light(t_ray ray, t_vector normal, t_scene scene,
void *obj);
t_frgb			compute_light_other(t_ray ray, t_vector normal, t_scene scene,
void *obj);

void			raytosphere(t_ray *ray, t_scene scene);
double			sphere_intersec_equation(t_ray *ray, t_sphere *sphere,
t_quadric *q);

void			raytoplane(t_ray *ray, t_scene scene);
double			plane_intersec_equation(t_ray *ray, t_plane *plane);

void			raytotriangle(t_ray *ray, t_scene scene);
double			triangle_intersec_equation(t_ray *ray, t_triangle *triangle,
t_vector *normal);

void			raytosquare(t_ray *ray, t_scene scene);
double			square_intersec_equation(t_ray *ray, t_square *square);

void			raytocylinder(t_ray *ray, t_scene scene);
double			cylinder_inter_equation(t_ray *ray, t_cylinder *cylinder,
t_quadric *q);

int				sphere_intersec(t_scene scene, t_ray *ray, double length);
int				triangle_intersec(t_scene scene, t_ray *ray, double length);
int				plane_intersec(t_scene scene, t_ray *ray, double length);
int				square_intersec(t_scene scene, t_ray *ray, double length);
int				cylinder_intersec(t_scene scene, t_ray *ray, double length);

void			create_bmp(t_scene scene, t_mlx *mlx_session);

#endif
