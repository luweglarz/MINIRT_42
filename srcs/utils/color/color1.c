/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:12:29 by user42            #+#    #+#             */
/*   Updated: 2021/02/09 12:18:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		color_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb	rgb_add(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	rgb3;

	rgb3.r = rgb1.r + rgb2.r;
	if (rgb3.r > 255)
		rgb3.r = 255;
	rgb3.g = rgb1.g + rgb2.g;
	if (rgb3.g > 255)
		rgb3.g = 255;
	rgb3.b = rgb1.b + rgb2.b;
	if (rgb3.b > 255)
		rgb3.b = 255;
	return (rgb3);
}

t_rgb	rgb_multipli(t_rgb color, double coeff)
{
	t_rgb	rgb;

	rgb.r = color.r * coeff;
	if (rgb.r > 255)
		rgb.r = 255;
	rgb.g = color.g * coeff;
	if (rgb.g > 255)
		rgb.g = 255;
	rgb.b = color.b * coeff;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

t_rgb	color_multipli(t_frgb frgb1, t_frgb frgb2)
{
	t_frgb	frgb3;

	frgb3.r = frgb1.r * frgb2.r;
	frgb3.g = frgb1.g * frgb2.g;
	frgb3.b = frgb1.b * frgb2.b;
	return (color_range2(frgb3));
}
