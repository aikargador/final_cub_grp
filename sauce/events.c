/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:39:28 by aikram            #+#    #+#             */
/*   Updated: 2023/11/22 12:22:51 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

int	handle_keypress(int keysym, t_able *table)
{
	if (keysym == A)
		table->keys[0] = true;
	else if (keysym == S)
		table->keys[1] = true;
	else if (keysym == D)
		table->keys[2] = true;
	else if (keysym == W)
		table->keys[3] = true;
	else if (keysym == LEFT)
		table->keys[4] = true;
	else if (keysym == RIGHT)
		table->keys[5] = true;
	return (0);
}

int	handle_keyrelease(int keysym, t_able *table)
{
	if (keysym == A)
		table->keys[0] = false;
	else if (keysym == S)
		table->keys[1] = false;
	else if (keysym == D)
		table->keys[2] = false;
	else if (keysym == W)
		table->keys[3] = false;
	else if (keysym == LEFT)
		table->keys[4] = false;
	else if (keysym == RIGHT)
		table->keys[5] = false;
	else if (keysym == ESC)
		exit (ultimate_destroyer(table));
	return (0);
}

int	mouse_hook(t_able *table)
{
	ultimate_destroyer(table);
	exit (0);
}

int	main_loop(t_able *table)
{
	handle_movements(table);
	calc(table);
	mlx_put_image_to_window(table->mlx.mlx, table->mlx.win, \
	table->mlx.img->img, 0, 0);
	return (0);
}
