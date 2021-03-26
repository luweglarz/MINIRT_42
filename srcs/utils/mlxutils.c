/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:45:03 by user42            #+#    #+#             */
/*   Updated: 2021/03/25 19:03:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


int		close_window(t_mlx *mlx_session)
{
	mlx_destroy_window(mlx_session->mlx, mlx_session->mlx_win);
	mlx_destroy_image(mlx_session->mlx, mlx_session->img.img);
	mlx_destroy_display(mlx_session->mlx);
	free(mlx_session->mlx);
	ft_lstclear(&mlx_session->scene.sphere, free);
	ft_lstclear(&mlx_session->scene.camera, free);
	ft_lstclear(&mlx_session->scene.square, free);
	ft_lstclear(&mlx_session->scene.plane, free);
	ft_lstclear(&mlx_session->scene.cylinder, free);
	ft_lstclear(&mlx_session->scene.triangle, free);
	ft_lstclear(&mlx_session->scene.light, free);
	exit(1);
}

int		key_code(int keycode, t_mlx *mlx_session)
{
	if (keycode == 65307)
		close_window(mlx_session);
	if (keycode == 100 || keycode == 97)
		cam_hook(keycode, mlx_session);
	return(0);
}

int		refresh_window(t_mlx *mlx_session)
{
	mlx_put_image_to_window(mlx_session->mlx,
	mlx_session->mlx_win, mlx_session->img.img, 0, 0);
	return (1);
}

void	init_mlx_window(t_mlx *mlx_session, t_scene scene)
{
	int	size_w;
	int	size_h;

	size_w = 0;
	size_h = 0;
	mlx_get_screen_size(mlx_session->mlx, &size_w, &size_h);
	if (scene.reso.w > size_w)
		scene.reso.w = size_w;
	if (scene.reso.h > size_h)
		scene.reso.h = size_h;
	mlx_session->mlx_win =
	mlx_new_window(mlx_session->mlx, scene.reso.w, scene.reso.h, "MiniRT");
}

void	init_mlx_image(t_mlx *mlx_session, t_scene scene)
{
	mlx_session->mlx = mlx_init();
	mlx_session->img.img =
	mlx_new_image(mlx_session->mlx, scene.reso.w, scene.reso.h);
	mlx_session->img.addr =
	mlx_get_data_addr(mlx_session->img.img, &mlx_session->img.bpp,
	&mlx_session->img.line_length, &mlx_session->img.endian);

}
