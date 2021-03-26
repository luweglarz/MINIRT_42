/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:15:08 by user42            #+#    #+#             */
/*   Updated: 2021/03/25 18:59:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	make_header(int fd, t_scene scene)
{
	int octet;
  	write(fd, "BM", 2); 
 	octet = 66;
 	write(fd, &octet, 4);
  	octet = 0;
  	write(fd, &octet, 2); 
  	write(fd, &octet, 2); 
 	octet = 54;
 	write(fd, &octet, 4);
 	octet = 40;
 	write(fd, &octet, 4);
  	write(fd, &scene.reso.w, 4);
  	write(fd, &scene.reso.h, 4);
  	octet = 1;
  	write(fd, &octet, 2);
  	octet = 32;
  	write(fd, &octet, 2); 
  	octet = 0;
  	write(fd, &octet, 4);
  	write(fd, &octet, 4);
  	write(fd, &octet, 4);
 	write(fd, &octet, 4);
 	write(fd, &octet, 4);
	write(fd, &octet, 4);
}

void	bmp_raytrace(int fd, t_scene scene, t_mlx *mlx_session)
{
	t_px		px;

	px.y = scene.reso.h;
	while (--px.y >= 0)
	{
		px.x = -1;
		while (++px.x < scene.reso.w)
		{
			write(fd, &mlx_session->img.addr[px.y * mlx_session->img.line_length + px.x * 4] , 4);
		}
	}
}

void create_bmp(t_scene scene, t_mlx *mlx_session)
{
	int				fd;

	fd = open("minirtscreen.bmp", O_WRONLY | O_CREAT | O_TRUNC);
	make_header(fd, scene);
	bmp_raytrace(fd, scene, mlx_session);
	close(fd);
	system("chmod 777 minirtscreen.bmp");
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