/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:51:23 by aikram            #+#    #+#             */
/*   Updated: 2023/11/20 21:14:35 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

void	ray_dir(t_able *table);
void	chk_wall_cnt(t_able *table);
void	draw_ray(t_able *table);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	*dst;

	dst = (int *)data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	calc(t_able *table)
{
	table->col = 0;
	while (table->col < WIDTH)
	{
		table->camx = 2 * table->col / (double)WIDTH - 1;
		table->ray.dir.x = table->plr.dir.x + table->plane.x * table->camx;
		table->ray.dir.y = table->plr.dir.y + table->plane.y * table->camx;
		table->ray.map.x = (int)table->plr.pos.x;
		table->ray.map.y = (int)table->plr.pos.y;
		table->ray.delta_dist.x = fabs(1 / table->ray.dir.x);
		table->ray.delta_dist.y = fabs(1 / table->ray.dir.y);
		table->ray.hit = 0;
		ray_dir(table);
		chk_wall_cnt(table);
		draw_ray(table);
		texture(table);
		table->col++;
	}
}

void	ray_dir(t_able *table)
{
	if (table->ray.dir.x < 0)
	{
		table->ray.step.x = -1;
		table->ray.side_dist.x = (table->plr.pos.x \
		- table->ray.map.x) * table->ray.delta_dist.x;
	}
	else
	{
		table->ray.step.x = 1;
		table->ray.side_dist.x = (table->ray.map.x \
		+ 1.0 - table->plr.pos.x) * table->ray.delta_dist.x;
	}
	if (table->ray.dir.y < 0)
	{
		table->ray.step.y = -1;
		table->ray.side_dist.y = (table->plr.pos.y \
		- table->ray.map.y) * table->ray.delta_dist.y;
	}
	else
	{
		table->ray.step.y = 1;
		table->ray.side_dist.y = (table->ray.map.y \
		+ 1.0 - table->plr.pos.y) * table->ray.delta_dist.y;
	}
}

void	chk_wall_cnt(t_able *table)
{
	while (!table->ray.hit)
	{
		if (table->ray.side_dist.x < table->ray.side_dist.y)
		{
			table->ray.side_dist.x += table->ray.delta_dist.x;
			table->ray.map.x += table->ray.step.x;
			if (table->ray.dir.x < 0)
				table->ray.side = 0;
			else
				table->ray.side = 2;
		}
		else
		{
			table->ray.side_dist.y += table->ray.delta_dist.y;
			table->ray.map.y += table->ray.step.y;
			if (table->ray.dir.y < 0)
				table->ray.side = 1;
			else
				table->ray.side = 3;
		}
		if (table->parse->map[table->ray.map.y][table->ray.map.x] == '1')
			table->ray.hit = 1;
	}
}

void	draw_ray(t_able *table)
{
	if (!table->ray.side || table->ray.side == 2)
		table->ray.perp_wall_dist = table->ray.side_dist.x \
		- table->ray.delta_dist.x;
	else
		table->ray.perp_wall_dist = table->ray.side_dist.y \
		- table->ray.delta_dist.y;
	if (table->ray.perp_wall_dist <= 0)
		table->ray.perp_wall_dist = 1;
	table->tex.line_hgt = (int)(HEIGHT / table->ray.perp_wall_dist);
	table->tex.draw_start = (HEIGHT / 2) - (table->tex.line_hgt / 2);
	if (table->tex.draw_start < 0)
		table->tex.draw_start = 0;
	table->tex.draw_end = (HEIGHT / 2) + (table->tex.line_hgt / 2);
	if (table->tex.draw_end >= HEIGHT)
		table->tex.draw_end = HEIGHT - 1;
}
