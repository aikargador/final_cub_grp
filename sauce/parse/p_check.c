/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:47:44 by aikram            #+#    #+#             */
/*   Updated: 2023/11/24 22:00:18 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	set_plr_pos(t_parse *parse, char **map, int y, int x)
{
	parse->pdir = map[y][x];
	parse->pos.y = y;
	parse->pos.x = x;
}

int	check_map_sides(t_imap *map, char **map_tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != '1')
		{
			return (SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_ifvalid(t_parse *parse, char **map)
{
	if (!parse->map)
		return (print_err(parse->imap.path, "ERR_MAP_MISSING", FAILURE));
	if (check_map_sides(&parse->imap, map) == FAILURE)
		return (print_err(parse->imap.path, "ERR_MAP_NO_WALLS", FAILURE));
	if (parse->imap.height < 3)
		return (print_err(parse->imap.path, "ERR_MAP_TOO_SMALL", FAILURE));
	if (check_map_elements(parse, map) == FAILURE)
		return (FAILURE);
	if (parse->pdir == '0' && parse->map != NULL)
		return (print_err(NULL, "NO_PLAYER_FOUND_ON_THE_FIELD", FAILURE));
	if (check_map_is_at_the_end(&parse->imap) == FAILURE)
		return (print_err(parse->imap.path, "ERR_MAP_LAST", FAILURE));
	return (SUCCESS);
}
