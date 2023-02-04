/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:21:43 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/02 13:02:30 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <math.h> 
# include <time.h>

# define LEFT_CLICK 1
# define RIGHT_CLICK 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win_ptr;
	int		width;
	int		height;
	int		**tab;
	t_data	*data;
} t_vars;


void put_rectangle(t_data *data,t_vars *vars ,int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif