/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:32:51 by aikram            #+#    #+#             */
/*   Updated: 2023/11/24 19:31:58 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

bool	loop_chk(size_t len, size_t idx, char *map)
{
	size_t	counter;

	counter = 0;
	while ((map[idx] == ' ' || map[idx] == '1' || !map[idx]) && counter < len)
	{
		counter++;
		idx++;
	}
	if (counter < len)
		return (false);
	return (true);
}

bool	chk_neighbours(size_t idx, char *map)
{
	if (!idx)
	{
		if (!loop_chk(2, idx, map))
			return (false);
	}
	else if (!map[idx + 1])
	{
		if (!loop_chk(2, idx - 1, map))
			return (false);
	}
	else
		if (!loop_chk(3, idx - 1, map))
			return (false);
	return (true);
}

bool	hole_detective(char **map, size_t x, size_t y, short l)
{
	while (map[y][x])
	{
		if (!y && map[y + 1] && map[y][x] == ' ')
		{
			if (!chk_neighbours(x, map[y]) \
			|| !chk_neighbours(x, map[y + 1]))
				return (true);
		}
		else if (!map[y + 1] && map[y][x] == ' ')
		{
			if (!chk_neighbours(x, map[y - 1]) \
			|| !chk_neighbours(x, map[y]))
				return (true);
		}
		else if (map[y][x] == ' ')
		{
			while (l < 2 && chk_neighbours(x, map[y + l]))
				l++;
			if (l < 2)
				return (true);
		}
		x++;
	}
	return (false);
}

int	chk_sneaky_space(char **map)
{
	size_t	i[2];

	ft_memset(i, 0, sizeof(size_t) * 2);
	while (map[i[0]])
	{
		if (hole_detective(map, i[1], i[0], -1))
			return (!print_and_return(BH));
		i[0]++;
	}
	return (!destroy_and_return(map, 0));
}
