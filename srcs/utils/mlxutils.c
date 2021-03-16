/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:45:03 by user42            #+#    #+#             */
/*   Updated: 2021/03/16 20:17:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		close_window(t_mlx *mlx_session)
{
	mlx_destroy_window(mlx_session->mlx, mlx_session->mlx_win);
	// free tout les by
	exit(0);
}

int		refresh_window(t_mlx *mlx_session)
{
	mlx_put_image_to_window(mlx_session->mlx,
	mlx_session->mlx_win, mlx_session->img.img, 0, 0);
	return (1);
}

void	init_mlx_window(t_mlx *mlx_session, t_scene *scene)
{
	int	size_w;
	int	size_h;

	size_w = 0;
	size_h = 0;
	mlx_session->mlx = mlx_init();
	mlx_get_screen_size(mlx_session->mlx, &size_w, &size_h);
	if (scene->reso.w > size_w)
		scene->reso.w = size_w;
	if (scene->reso.h > size_h)
		scene->reso.h = size_h;
	mlx_session->mlx_win =
	mlx_new_window(mlx_session->mlx, scene->reso.w, scene->reso.h, "MiniRT");
}

void	init_mlx_image(t_mlx *mlx_session, t_scene *scene)
{
	mlx_session->img.img =
	mlx_new_image(mlx_session->mlx, scene->reso.w, scene->reso.h);
	mlx_session->img.addr =
	mlx_get_data_addr(mlx_session->img.img, &mlx_session->img.bpp,
	&mlx_session->img.line_length, &mlx_session->img.endian);

}

void	keys(t_mlx mlx_session)
{
	mlx_key_hook(mlx_session.mlx_win, cam_hook, &mlx_session);
	mlx_hook(mlx_session.mlx_win, 33, 1L << 17, close_window, &mlx_session);
	mlx_hook(mlx_session.mlx_win, 9, 1L << 21, refresh_window, &mlx_session);
}