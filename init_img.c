/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:21:48 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/04 12:21:50 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game_of_life.h"

void	init_img(t_vars *vars, t_data *data)
{
	data->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length,
								   &data->endian);
	vars->data = data;
}