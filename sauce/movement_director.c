/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_director.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:14:53 by aikram            #+#    #+#             */
/*   Updated: 2023/11/13 20:58:01 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

void	plyr_rt_and_mv(t_able *table, int rt, int mv)
{
	if (rt)
		plyr_rt(table);
	else
		plyr_rrt(table);
	plyr_mvment(table, mv);
}

void	plyr_rt_and_strf(t_able *table, int rt, int strf)
{
	if (rt)
		plyr_rt(table);
	else
		plyr_rrt(table);
	plyr_strafe(table, strf);
}

void	strafe_and_move(t_able *table, int mv, int strf)
{
	plyr_strafe(table, strf);
	plyr_mvment(table, mv);
}

void	mv_strf_rt(t_able *table, int mv, int strf, int rt)
{
	plyr_mvment(table, mv);
	plyr_strafe(table, strf);
	if (rt)
		plyr_rt(table);
	else
		plyr_rrt(table);
}
