/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:42:32 by aikram            #+#    #+#             */
/*   Updated: 2023/11/13 20:56:19 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

void	plyr_rt(t_able *table)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = table->plr.dir.x;
	table->plr.dir.x = table->plr.dir.x * cos(-table->plr.rt_spd) \
	- table->plr.dir.y * sin(-table->plr.rt_spd);
	table->plr.dir.y = old_dirx * sin(-table->plr.rt_spd) \
	+ table->plr.dir.y * cos(-table->plr.rt_spd);
	old_planex = table->plane.x;
	table->plane.x = table->plane.x * cos(-table->plr.rt_spd) \
	- table->plane.y * sin(-table->plr.rt_spd);
	table->plane.y = old_planex * sin(-table->plr.rt_spd) \
	+ table->plane.y * cos(-table->plr.rt_spd);
}

void	plyr_rrt(t_able *table)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = table->plr.dir.x;
	table->plr.dir.x = table->plr.dir.x * cos(table->plr.rt_spd) \
	- table->plr.dir.y * sin(table->plr.rt_spd);
	table->plr.dir.y = old_dirx * sin(table->plr.rt_spd) \
	+ table->plr.dir.y * cos(table->plr.rt_spd);
	old_planex = table->plane.x;
	table->plane.x = table->plane.x * cos(table->plr.rt_spd) \
	- table->plane.y * sin(table->plr.rt_spd);
	table->plane.y = old_planex * sin(table->plr.rt_spd) \
	+ table->plane.y * cos(table->plr.rt_spd);
}

void	plyr_mvment(t_able *table, int forward)
{
	if (forward)
	{
		if (table->parse->map[(int)(table->plr.pos.y)][(int)(table->plr.pos.x \
		+ table->plr.dir.x * table->plr.mv_spd)] != '1')
			table->plr.pos.x += table->plr.dir.x * table->plr.mv_spd;
		if (table->parse->map[(int)(table->plr.pos.y + table->plr.dir.y \
		* table->plr.mv_spd)][(int)(table->plr.pos.x)] != '1')
			table->plr.pos.y += table->plr.dir.y * table->plr.mv_spd;
	}
	else
	{
		if (table->parse->map[(int)(table->plr.pos.y - table->plr.dir.y \
		* table->plr.mv_spd)][(int)(table->plr.pos.x)] != '1')
			table->plr.pos.y -= table->plr.dir.y * table->plr.mv_spd;
		if (table->parse->map[(int)(table->plr.pos.y)][(int)(table->plr.pos.x \
		- table->plr.dir.x * table->plr.mv_spd)] != '1')
			table->plr.pos.x -= table->plr.dir.x * table->plr.mv_spd;
	}
}

void	plyr_strafe(t_able *table, int right)
{
	if (right)
	{
		if (table->parse->map[(int)(table->plr.pos.y - table->plr.dir.x \
		* table->plr.mv_spd)][(int)(table->plr.pos.x)] != '1')
			table->plr.pos.y -= table->plr.dir.x * table->plr.mv_spd;
		if (table->parse->map[(int)(table->plr.pos.y)][(int)(table->plr.pos.x \
		+ table->plr.dir.y * table->plr.mv_spd)] != '1')
			table->plr.pos.x += table->plr.dir.y * table->plr.mv_spd;
	}
	else
	{
		if (table->parse->map[(int)(table->plr.pos.y + table->plr.dir.x \
		* table->plr.mv_spd)][(int)(table->plr.pos.x)] != '1')
			table->plr.pos.y += table->plr.dir.x * table->plr.mv_spd;
		if (table->parse->map[(int)(table->plr.pos.y)][(int)(table->plr.pos.x \
		- table->plr.dir.y * table->plr.mv_spd)] != '1')
			table->plr.pos.x -= table->plr.dir.y * table->plr.mv_spd;
	}
}
