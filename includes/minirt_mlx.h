/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:29:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/26 18:43:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MLX_H
# define MINIRT_MLX_H

# include "minirt.h"

typedef struct	s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
	t_scene		scene;
	t_list		*camera_list;
	int			nb_cam;
}				t_mlx;

void			init_mlx_window(t_mlx *mlx_session, t_scene scene);
void			init_mlx_image(t_mlx *mlx_session, t_scene scene);
void			my_pixel_put(t_img_data *data, t_px px, t_rgb *rgb);
int				refresh_window(t_mlx *mlx_session);
int				key_code(int keycode, t_mlx *mlx_session);
int				close_window(t_mlx *mlx_session);

#endif
