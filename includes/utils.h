/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:28:10 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/02 16:33:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

# define BUFFER_SIZE 128

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
	double		ray_t;
	t_rgb		ray_color;
	void		*obj;
}				t_ray;

typedef struct	s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img_data;

void			ft_bzero(void *s, size_t n);
char			*ft_strdup(char *s);
char			*ft_substr(char *s, int start, int len);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);
int				get_next_line(int fd, char **line);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlenc(char *str, char c);
int				ft_atoi(const char *nptr);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
float			ft_atof(char *nptr);

double			vec_dot(t_vector v1, t_vector v2);
double			vec_length(t_vector v1);
t_vector		vec_diff(t_vector v1, t_vector v2);
t_vector		vec_multipli_coeff(t_vector v1, double coeff);
t_vector		vec_add(t_vector v1, t_vector v2);
t_vector		vec_div(t_vector v1, double nb);

t_rgb			rgb_multipli(t_rgb color, double coeff);
void			my_pixel_put(t_img_data *data, int x, int y, t_rgb *rgb);
int				color_to_int(t_rgb rgb);
t_vector		normalize(t_vector vec);
t_vector		ray_equation(t_ray *ray, double ray_t);
void			color_init(t_rgb *rgb);
t_frgb			color_range1(t_rgb rgb);
t_rgb			color_range2(t_frgb frgb);
t_rgb			rgb_add(t_rgb rgb1, t_rgb rgb2);
t_rgb			color_multipli(t_frgb frgb1, t_frgb frgb2);
#endif
