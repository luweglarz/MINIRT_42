/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:56 by lweglarz          #+#    #+#             */
/*   Updated: 2021/02/15 15:11:16 by user42           ###   ########.fr       */
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
t_rgb	trace_ray(t_ray ray, t_scene *scene, int x, int y);

void		raytosphere(t_ray *ray, t_scene *scene);
void	sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t);
void	sphere_intersec_color(t_sphere *sphere, t_ray *ray, t_scene *scene);
t_frgb	compute_light(t_vector ray_pos, t_vector normal, t_scene *scene);
void		raytoplane(t_ray *ray, t_scene *scene);
#endif
