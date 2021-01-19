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

int		sphereintersec(t_ray *ray, t_sphere *sphere, double *t1, double *t2);
int		raytosphere(t_ray *ray, t_scene *scene, t_rgb *obj_color);
void	ray_init(t_ray *ray);
t_rgb	trace_ray(t_ray ray, t_scene *scene);
void	ray_tracer(t_scene *scene);
#endif
