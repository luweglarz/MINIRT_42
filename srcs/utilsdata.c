/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:25:05 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/27 16:16:22 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	*get_color(char **rgbtab)
{
	t_rgb	*rgb;

	if (!(rgb = malloc(sizeof(t_rgb))))
		write(2, "error", 5);
	rgb->r = ft_atoi(rgbtab[0]);
	rgb->g = ft_atoi(rgbtab[1]);
	rgb->b = ft_atoi(rgbtab[2]);
	if (rgb->r > 255 || rgb->g > 255 || rgb->b > 255)
		write(2, "error", 5);
	return (rgb);
}
