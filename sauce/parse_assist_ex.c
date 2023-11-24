/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assist_ex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:30:48 by aikram            #+#    #+#             */
/*   Updated: 2023/11/24 18:31:51 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

int	destroy_and_return(char **pad, int msg)
{
	size_t	i;

	i = 0;
	if (msg)
		write(2, PALLOC, ft_strlen(PALLOC));
	if (pad)
	{
		while (pad[i])
			free(pad[i++]);
		free(pad);
	}
	return (1);
}

char	*copy_and_pad(char *src, size_t size)
{
	size_t	i;
	char	*pad;

	i = 0;
	pad = ft_calloc((size + 1), sizeof(char));
	if (!pad)
		return (NULL);
	while (src[i] && i < size)
	{
		pad[i] = src[i];
		i++;
	}
	while (i < size)
		pad[i++] = ' ';
	return (pad);
}

int	padder_pooper(char **map)
{
	size_t				i[3];
	char				**pad;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (map[i[0]])
	{
		if (ft_strlen(map[i[0]]) > i[1])
			i[1] = ft_strlen(map[i[0]]);
		i[0]++;
	}
	pad = ft_calloc(i[0] + 1, sizeof(char *));
	if (!pad)
		return (1);
	while (i[2] < i[0])
	{
		pad[i[2]] = copy_and_pad(map[i[2]], i[1]);
		if (!pad[i[2]])
			return (destroy_and_return(pad, 1));
		i[2]++;
	}
	return (chk_sneaky_space(pad));
}
