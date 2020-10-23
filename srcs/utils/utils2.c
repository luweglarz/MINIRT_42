/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:53:51 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/23 14:45:45 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

int		ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	isnegative;

	nbr = 0;
	isnegative = 1;
	i = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			isnegative = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (isnegative * nbr);
}

float	ft_atof(char *nptr)
{
	float	ent;
	float	dec;
	int		size;

	ent = (float)ft_atoi(nptr);
	while (*nptr && *nptr != '.')
		nptr++;
	if (*nptr == '.')
		nptr++;
	dec = (float)(ft_atoi(nptr));
	size = ft_strlen(nptr);
	while (size--)
		dec /= 10;
	if (ent < 0)
		return ((ent + -dec));
	return ((ent + dec) * 1);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
