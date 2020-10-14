/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:30:07 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/14 15:50:46 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
    t_scene *scene;
    int fd; //  gestion d erreur a faire
    fd = open(argv[1], O_RDONLY); // pareil
    scene = parsing_config(argv[1]);
    
}