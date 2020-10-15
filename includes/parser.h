/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:42:16 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/15 12:23:11 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PASTER_H

#define SPHERE "sp"
#define RES 'R'

#include "minirt.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_scene     *parsing_config(int fd);
void        init_scene(t_scene *scene);
t_scene     append_data(t_scene **scene, char *line);
t_scene 	get_resolution(t_scene *scene, char *line);
t_scene 	get_sphere(t_scene *scene, char *line);
#endif