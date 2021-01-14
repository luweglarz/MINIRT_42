/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:47:42 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 11:24:53 by lweglarz         ###   ########.fr       */
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
	unsigned int		w;
	unsigned int		h;
}					t_reso;

typedef struct		s_amli
{
	float	ratio;
	t_rgb	color;
}					t_amli;

typedef struct		s_camera
{
	t_vector			cord;
	t_vector			ori;
	unsigned int		fov;
}					t_camera;

typedef struct		s_light
{
	t_vector			cord;
	float				ratio;
	t_rgb				color;
}					t_light;

typedef struct		s_sphere
{
	t_vector			cord;
	float				radius;
	t_rgb				color;
}					t_sphere;

typedef struct		s_plane
{
	t_vector			cord;
	t_vector			ori;
	t_rgb				color;
}					t_plane;

typedef struct		s_square
{
	t_vector			cord;
	t_vector			ori;
	float				height;
	t_rgb				color;
}					t_square;

typedef struct		s_cylinder
{
	t_vector			cord;
	t_vector			ori;
	float				diameter;
	float				height;
	t_rgb				color;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector			cord1;
	t_vector			cord2;
	t_vector			cord3;
	t_rgb				color;
}					t_triangle;

typedef struct		s_scene
{
	t_reso				reso;
	t_amli				amli;
	t_list				*camera;
	t_list				*light;
	t_list				*sphere;
	t_list				*plane;
	t_list				*square;
	t_list				*cylinder;
	t_list				*triangle;
}					t_scene;

#endif
