/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:20:26 by mparisse          #+#    #+#             */
/*   Updated: 2023/02/02 13:15:52 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"
#include <X11/X.h>

int init_vars_image(t_vars *vars, t_data *data)
{
	vars->mlx = mlx_init();
	vars->width = 800;
	vars->height = 800;
	vars->win_ptr = mlx_new_window(vars->mlx, vars->width, vars->height, "Game of Life");
	data->img = mlx_new_image(vars->mlx, vars->width, vars->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length,
								   &data->endian);
	vars->data = data;
	// line length = image height * 4
	// bits per pixel = 32 >> 4 octets
	return (0);
}

void print_double_tab(int **tab, int x, int y)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%d", tab[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int ft_close(t_vars *vars)
{
	print_double_tab(vars->tab, vars->width/10, vars->height/10);
	free(vars->mlx);
	free(vars->win_ptr);
	exit(0);
}

/*
- si un carre a deux ou trois voisin est qu'il est deja vivant il reste vivant
- siun carre a trois voisin et il est mort il nait

n'oublie pas les diagonales
*/

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		free(vars->mlx);
		free(vars->win_ptr);
		exit(0);
	}
	return (1);
}

void put_rectangle(t_data *data, int x, int y, int color)
{
	int limitx;
	int limity;
	int keepx;

	keepx = x;
	limitx = x + 10;
	limity = y + 10;
	while (y < limity)
	{
		x = keepx - 1;
		while (++x < limitx)
			my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

int find_nearest_tens(int x)
{
	return ((x + 5) / 10 * 10);
}

int mouse_hook(int button ,int x, int y, t_vars *vars)
{
	int putx;
	int puty;

	if (button == 1 && x < vars->width && y < vars->height)
	{
		putx = find_nearest_tens(x);
		puty = find_nearest_tens(y);
		put_rectangle(vars->data, putx, puty, 0xffffff);
		vars->tab[putx/10][puty/10] = 1;
	}
	if (button == 3 && x < vars->width && y < vars->height)
	{
		printf("%d %d\n", x, y);
		putx = find_nearest_tens(x);
		puty = find_nearest_tens(y);
		put_rectangle(vars->data, putx, puty, 0x000000);
	}
	mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->data->img, 0, 0);
	return (0);
}

int main()
{
	t_vars vars;
	t_data data;
	int		**tab;

	init_vars_image(&vars, &data);
	// printf("mon tableau contiendra >> %d carre\n", (vars.width)/10);
	tab = calloc(sizeof(int *), (vars.width/10));
	if (!tab)
		return (0);
	for (int i = 0;i < vars.height/10; i++)
		tab[i] = calloc(sizeof(int), vars.height/10);
	vars.tab = tab;
	// put_rectangle(&data, 400, 400);
	mlx_mouse_hook(vars.win_ptr, &mouse_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 0, &ft_close, &vars);
	// mlx_hook(vars.win_ptr, MotionNotify, PointerMotionMask, &mouse_hook, &vars);
	mlx_key_hook(vars.win_ptr, &key_hook, &vars);
	mlx_loop(vars.mlx);
}
