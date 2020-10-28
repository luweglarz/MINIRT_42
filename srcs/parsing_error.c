/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:38:38 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/28 12:20:09 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void    error(int errorcode)
{
    // a voir fonction perror et strerror
    if (errorcode == ERR_NBFILE)
        write(STDERR_FILENO, "Too much arguments", 18);
    if (errorcode == ERR_FEWFILE)
        write(STDERR_FILENO, "Too few arguments", 17);
    if (errorcode == ERR_SAVE)
        write(STDERR_FILENO, "3rd argument must be \"-save\"", 29);
    if (errorcode == ERR_MALLOC)
        write(STDERR_FILENO, "Malloc failed", 13);
    if (errorcode == ERR_ELEMENT)
        write (STDERR_FILENO, "Wrong element value given", 25);
    exit(errorcode);
}