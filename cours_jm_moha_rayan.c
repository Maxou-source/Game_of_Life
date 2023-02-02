/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cours_jm_moha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:45:35 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/02 09:46:08 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// ft_printf("dst : %d\n\n", dst);
	// 1 octet >> 8 bits
	// 4 octets >> 32 bits 
	// 1 pixel >> 4 octets >> 32 bits (a 42)
	// j'ai besoin de l'adresse en octet (ptr)
	// on va avancer dans le pointeur de l'image
	// data addr >> addr du premier pixel 0, 0
	// y * data line lenght >> c l'adresse du point a la position y 
	// x * (bits_per_pixel / 8) >> un pixel occup un 4 octets = 32 bits 
	// je divise par 8 car je veux l'adresse en memoire du premier 
	// octet, des 4 octets composant un pixel 
	/*
	    line length 
	_________________
	|
	|
	|     
	|
	|
	|
	*/
	*(unsigned int *)dst = color;
	// on le recast en unsigned pour avoir la couleur 
}