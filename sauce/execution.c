/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:10:39 by aikram            #+#    #+#             */
/*   Updated: 2023/11/24 19:30:25 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

bool	mlx_starter(t_able *table)
{
	table->mlx.mlx = mlx_init();
	if (!table->mlx.mlx)
		return (free_table(table, MINT));
	table->mlx.win = mlx_new_window(table->mlx.mlx, WIDTH, HEIGHT, "mlx");
	if (!table->mlx.win)
		return (free_table(table, MWIN));
	table->mlx.img = new_image(table, false);
	if (!table->mlx.img)
		return (free_table(table, MIMG));
	if (init_texture(table))
		return (false);
	mlx_hook(table->mlx.win, 03, 1L << 1, &handle_keyrelease, table);
	mlx_hook(table->mlx.win, 02, 1L << 0, &handle_keypress, table);
	mlx_hook(table->mlx.win, 17, 1 << 10, &mouse_hook, table);
	mlx_loop_hook(table->mlx.mlx, &main_loop, table);
	mlx_loop(table->mlx.mlx);
	return (true);
}

void	plr_init(t_able *table)
{
	if (table->parse->pdir == 'N')
	{
		table->plr.dir.y = -1;
		table->plane.x = -0.80;
	}
	else if (table->parse->pdir == 'S')
	{
		table->plr.dir.y = 1;
		table->plane.x = 0.80;
	}
	else if (table->parse->pdir == 'W')
	{
		table->plr.dir.x = 1;
		table->plane.y = -0.80;
	}
	else
	{
		table->plr.dir.x = -1;
		table->plane.y = 0.80;
	}
	table->plr.pos.x = table->parse->pos.x + .5;
	table->plr.pos.y = table->parse->pos.y + .5;
	table->plr.mv_spd = 0.03;
	table->plr.rt_spd = 0.025;
}

void	init_table(t_able *table, t_parse *parse, t_data *data)
{
	ft_bzero(table, sizeof(t_able));
	table->parse = parse;
	table->data = data;
}

int	eggsecute(t_parse *parse, t_data *data)
{
	t_able	table;

	init_table(&table, parse, data);
	texture_path_match(&table);
	plr_init(&table);
	if (!mlx_starter(&table))
		return (69);
	return (0);
}
