/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:42:16 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/22 12:29:52 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

# define RES "R"
# define AMLIGHT "A"
# define CAMERA "c"
# define LIGHT "l"
# define SPHERE "sp"
# define PLANE "pl"
# define SQUARE "sq"
# define CYLINDER "cl"
# define TRIANLGE "tr"

typedef	void	(*t_get_elem)(t_scene *scene, char **data);

typedef struct	s_tab
{
	char			*data_type;
	int				data_len;
	t_get_elem		func;

}				t_tab;

void			parsing_config(t_scene *scene, int fd);
void			init_scene(t_scene *scene);
void			free_data(char **data);
void			append_data(t_scene *scene, char *line);

void			get_resolution(t_scene *scene, char **data);
void			get_amlight(t_scene *scene, char **data);
void			get_camera(t_scene *scene, char **data);
void			get_light(t_scene *scene, char **data);

void			get_sphere(t_scene *scene, char **data);
void			get_square(t_scene *scene, char **data);
void			get_cylinder(t_scene *scene, char **data);
void			get_triangle(t_scene *scene, char **data);
void			get_plane(t_scene *scene, char **data);

#endif
