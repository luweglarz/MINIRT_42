/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/20 17:42:12 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_scene *scene;
    int fd; //  gestion d erreur a faire
    
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY); // pareil
        scene = parsing_config(fd);
        close(fd);
    }
    else
        write(STDERR_FILENO, "error", 5);
}
