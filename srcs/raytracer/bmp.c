/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:15:08 by user42            #+#    #+#             */
/*   Updated: 2021/03/21 19:20:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
  	write(fd, "BM", 2); 

 	 octet = 14 + 40 + 4 * scene->reso.w * scene->reso.h;
 	 write(fd, &octet, 4);
  	octet = 0;
  	write(fd, &octet, 2); 
  	write(fd, &octet, 2); 
 	 octet = 54;
 	write(fd, &octet, 4);
 	 octet = 40;
 	 write(fd, &octet, 4);
  	write(fd, & scene->reso.w, 4);
  	write(fd, &scene->reso.h, 4);
  	octet = 1;
  	write(fd, &octet, 2);
  	octet = 32
  	write(fd, &octet, 2); 
  	octet = 0;
  	write(fd, &octet, 4);
  	write(fd, &octet, 4);
  	write(fd, &octet, 4);
 write(fd, &octet, 4);
 	write(fd, &toctetmp, 4);
 write(fd, &octet, 4);
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	make_header(unsigned char *header, t_scene *scene)
{
	ft_memset(header, 0, 54);
 	header[0] = 'B';
  	header[1] = 'M';
  	header[2] = 14 + 40 + 4 * scene->reso.h * scene->reso.w;
	header[10] = 54;
	header[14] = 40;
	header[18] = scene->reso.w;
	header[22] = scene->reso.h;
	header[26] = 1;
	header[28] = 24;
}


void	bmp_raytrace(int fd, t_scene *scene)
{
	t_px		px;
	t_rgb		color;
	t_ray		ray;
	t_list		*camera_list;
	t_camera	*camera;

	px.x = 0;
	camera_list = scene->camera;
	camera = camera_list->content;
	while (++px.x < scene->reso.w)
	{
		px.y = 0;
		while (++px.y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, camera, px, scene);
			color = trace_ray(ray, scene);
			write(fd, , );
		}
	}

}

void create_bmp(t_scene *scene)
{
	int				fd;
	unsigned char	header[54];

	fd = open("minirt", O_WRONLY | O_CREAT | O_TRUNC);
	make_header(header, scene);
	write(fd, header, 54);
	bmp_raytrace(fd, scene);
	close(fd);
}