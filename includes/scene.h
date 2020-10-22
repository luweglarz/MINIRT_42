/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:47:42 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/22 13:01:45 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct		s_vector
{
	float	x;
	float	y;
	float	z;
}					t_vector;

typedef struct		s_rgb
{
	int		r;
	int		g;
	int		b;
}					t_rgb;

typedef struct		s_reso
{
	int		w;
	int		h;
}					t_reso;

typedef struct		s_amli
{
	float	ratio;
	t_rgb	color;
}					t_amli;

typedef struct		s_camera
{
	t_vector			cordo;
	t_vector			ori;
	float				fov;
	struct s_camera		*next_cam;
}					t_camera;

typedef struct		s_light
{
	t_vector			lightp;
	float				ratio;
	t_rgb				color;
	struct s_light		*next_light;
}					t_light;

typedef struct		s_sphere
{
	t_vector			cordo;
	float				radius;
	t_rgb				color;
	struct s_sphere		*next_sphere;
}					t_sphere;

typedef struct		s_plane
{
	t_vector			cordo;
	t_vector			v1;
	t_vector			v2;
	t_vector			v3;
	t_rgb				color;
	struct s_plane		*next_plane;
}					t_plane;

typedef struct		s_square
{
	t_vector			cordo;
	t_vector			ori;
	float				height;
	t_rgb				color;
	struct s_square		*next_square;
}					t_square;

typedef struct		s_cylinder
{
	t_vector			cordo;
	t_vector			v1;
	t_vector			v2;
	t_vector			v3;
	float				ratios;
	float				height;
	struct s_cylinder	*next_cylinder;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector			cordo1;
	t_vector			cordo2;
	t_vector			cordo3;
	t_rgb				color;
	struct s_triangle	*next_triangle;
}					t_triangle;

typedef struct		s_scene
{
	t_reso		resolution;
	t_amli		amli;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_square	*square;
	t_cylinder	*cylinder;
	t_triangle	*triangle;
}					t_scene;

#endif
