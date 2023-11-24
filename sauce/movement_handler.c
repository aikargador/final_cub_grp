/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:33:37 by aikram            #+#    #+#             */
/*   Updated: 2023/11/13 20:59:18 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

bool	handle_movements_util0(t_able *table)
{
	if (table->keys[3] && table->keys[4])
		plyr_rt_and_mv(table, 0, 1);
	else if (table->keys[3] && table->keys[5])
		plyr_rt_and_mv(table, 1, 1);
	else if (table->keys[1] && table->keys[4])
		plyr_rt_and_mv(table, 0, 0);
	else if (table->keys[1] && table->keys[5])
		plyr_rt_and_mv(table, 1, 0);
	else if (table->keys[4] && table->keys[2])
		plyr_rt_and_strf(table, 0, 1);
	else if (table->keys[5] && table->keys[2])
		plyr_rt_and_strf(table, 1, 1);
	else if (table->keys[4] && table->keys[0])
		plyr_rt_and_strf(table, 0, 0);
	else if (table->keys[5] && table->keys[0])
		plyr_rt_and_strf(table, 1, 0);
	else
		return (false);
	return (true);
}

bool	handle_movements_util1(t_able *table)
{
	if (table->keys[3] && table->keys[2])
		strafe_and_move(table, 1, 1);
	else if (table->keys[3] && table->keys[0])
		strafe_and_move(table, 1, 0);
	else if (table->keys[1] && table->keys[2])
		strafe_and_move(table, 0, 1);
	else if (table->keys[1] && table->keys[0])
		strafe_and_move(table, 0, 0);
	else if (table->keys[3] && table->keys[2] && table->keys[4])
		mv_strf_rt(table, 1, 1, 0);
	else if (table->keys[3] && table->keys[2] && table->keys[5])
		mv_strf_rt(table, 1, 1, 1);
	else if (table->keys[3] && table->keys[0] && table->keys[4])
		mv_strf_rt(table, 1, 0, 0);
	else if (table->keys[3] && table->keys[0] && table->keys[5])
		mv_strf_rt(table, 1, 0, 1);
	else if (table->keys[1] && table->keys[2] && table->keys[4])
		mv_strf_rt(table, 0, 1, 0);
	else if (table->keys[1] && table->keys[0] && table->keys[5])
		mv_strf_rt(table, 0, 0, 1);
	else
		return (false);
	return (true);
}

void	handle_movements(t_able *table)
{
	if (handle_movements_util0(table))
		;
	else if (handle_movements_util1(table))
		;
	else if (table->keys[0])
		plyr_strafe(table, 0);
	else if (table->keys[2])
		plyr_strafe(table, 1);
	else if (table->keys[1])
		plyr_mvment(table, 0);
	else if (table->keys[3])
		plyr_mvment(table, 1);
	else if (table->keys[5])
		plyr_rt(table);
	else if (table->keys[4])
		plyr_rrt(table);
}
