/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:42:16 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/25 18:54:51 by user42           ###   ########.fr       */
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
# define CYLINDER "cy"
# define TRIANLGE "tr"

# define ERR_NBFILE -1
# define ERR_FEWFILE -2
# define ERR_SAVE -3
# define ERR_MALLOC -4
# define ERR_ELEMENT -5

typedef struct	s_tab
{
	char			*data_type;
	int				data_len;
	void			(*tab_elem)(t_scene *scene, char **data);
}				t_tab;

t_scene			parsing_config(int fd);
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

t_rgb			get_color(char **rgbtab);
t_vector		get_orientation(char **ori);
t_vector		get_cord(char	**cord);

void			error(int errorcode);
#endif
