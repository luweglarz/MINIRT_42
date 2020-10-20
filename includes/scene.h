/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:47:42 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/20 12:49:49 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include "minirt.h"

typedef struct      s_vector
{
    float       x;
    float       y;
    float       z;
}                   t_vector;

typedef struct      s_rgb  //RGB systeme de codage des couleurs a partir de trois couleurs primaire red, green ,blue, chaque valeur exprime une intervalle de 0 a 100%  par rapport a 255
{
    int r; //red
    int g; //green
    int b; //blue 
}                  t_rgb;

typedef struct      s_reso //resolution ecran
{
    int w; //width
    int h; //height 
}                   t_reso;

typedef struct      s_amli //lumiere ambiante 
{
    float       ratio; //ratio dans le range [0.0,1.0]
    t_rgb       color; // couleurs RGB dans le range [0-255]

}                   t_amli;

typedef struct      s_camera //parametre de la camera
{
    t_vector    cordo; //cordonne du point de vue 
    t_vector    ori; // vecteur de l'orientation 3d dans le range [-1,1] pour chaque axe x,y,z
    float       fov; // champ de vision horizontal en degres dans le range [0-180]
    struct      s_camera *next_cam;
}                   t_camera;

typedef struct      s_light
{
    t_vector     lightp; //coordonnées x,y,z du point Lumière
    float        ratio; //ratio de lumnosité dans le range [0.0,1.0]
    t_rgb        color; //Couleurs R,G,B dans le range [0-255]
}                   t_light;

typedef struct       s_sphere
{
    t_vector    cordo;
    float       radius;
    t_rgb       color;

}                    t_sphere;

typedef struct      s_scene
{
    t_reso      *resolution;
    t_amli      *amli;
    t_camera    *camera;
    t_light     *light;
    t_sphere    *sphere;
}                   t_scene;


#endif