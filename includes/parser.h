/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:42:16 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/15 16:31:36 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "minirt.h"

#define RES 'R'
#define AMLIGHT 'A'
#define CAMERA 'c'
#define LIGHT 'l'
#define SPHERE "sp"
#define PLANE 'pl'
#define SQUARE 'sq'
#define CYLINDER 'cl'
#define TRIANLGE 'tr'

t_scene     *parsing_config(int fd);
void        init_scene(t_scene **scene);
t_scene     append_data(t_scene **scene, char *line);

t_scene 	get_resolution(t_scene *scene, char **data);
t_scene     get_amlight(t_scene *scene, char **data);
t_scene     get_camera(t_scene *scene, char **data);
t_scene     get_light(t_scene *scene, char **data);

t_scene 	get_sphere(t_scene *scene, char **data);
t_scene     get_square(t_scene *scene, char **data);
t_scene     get_cylinder(t_scene *scene, char **data);
t_scene     get_triangle(t_scene *scene, char **data);

#endif