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


void	fill_sizes(unsigned char *header, unsigned int height,
					unsigned int width)
{
	unsigned int pixels_in_row;
	unsigned int padding_in_row;

	*(unsigned int *)(&header[18]) = width;
	*(unsigned int *)(&header[22]) = height;
	pixels_in_row = width * sizeof(t_pixel);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	header[2] = 54 + (pixels_in_row + padding_in_row) * height;
}
int		write_bmp(char *filename, unsigned int width, unsigned int height,
					t_pixel **pixels)
{
	int				fd;
	unsigned char	header[54];

	fill_header(header);
	fill_sizes(header, height, width);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	write(fd, header, 54);
	write_file(height, width, pixels, fd);
	close(fd);
	return (0);
}

int create_bmp(t_scene *scene, t_camera *camera)
{
	t_px		px;
	t_rgb		color;
	t_ray		ray;
	t_px		**buffer;

	px.x = 0;
	buffer = create_buffer(scene->reso.h, scene->reso.w);
	while (++px.x < scene->reso.w)
	{
		px.y = 0;
		while (++px.y < scene->reso.h)
		{
			ray_init(&ray);
			color_init(&color);
			init_camera(&ray, camera, px, scene);
			color = trace_ray(ray, scene);
			buffer[px.x][px.y] = ;
		}
	}
		write_bmp("file.bmp", scene->reso.w, scene->reso.h, buffer);
//	free_buffer
}