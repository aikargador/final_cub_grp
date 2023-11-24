/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:21:30 by aikram            #+#    #+#             */
/*   Updated: 2023/11/22 11:46:00 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

void	texture_path_match(t_able *table)
{
	table->swen_pth[0] = table->parse->so_text;
	table->swen_pth[1] = table->parse->we_text;
	table->swen_pth[2] = table->parse->ea_text;
	table->swen_pth[3] = table->parse->no_text;
}

bool	load_texture(t_able *table, size_t *tex, char *path)
{
	t_img	tmp;
	int		txhw;
	int		yx[2];

	txhw = TEXDIM;
	ft_memset(yx, -1, sizeof(int) * 2);
	tmp.img = mlx_xpm_file_to_image(table->mlx.mlx, path, &txhw, &txhw);
	if (!tmp.img)
		return (print_and_return(MXTI));
	tmp.addr = (int *)mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.line_len, \
	&tmp.endian);
	if (!tmp.addr)
		return (print_and_return(MGDA_SUSO));
	while (++yx[0] < TEXDIM)
	{
		yx[1] = -1;
		while (++yx[1] < TEXDIM)
			tex[(TEXDIM * yx[0]) + yx[1]] = tmp.addr[(TEXDIM * yx[0]) + yx[1]];
	}
	mlx_destroy_image(table->mlx.mlx, tmp.img);
	return (true);
}

bool	init_texture(t_able *table)
{
	int	i;

	i = -1;
	table->swen_tx = malloc(4 * sizeof(size_t *));
	if (!table->swen_tx)
		return (free_table(table, AIPP));
	while (++i < 4)
		table->swen_tx[i] = NULL;
	i = -1;
	while (++i < 4)
	{
		table->swen_tx[i] = malloc((TEXDIM * TEXDIM) * sizeof(size_t));
		if (!table->swen_tx[i])
			return (free_table(table, AIP));
		if (!load_texture(table, table->swen_tx[i], table->swen_pth[i]))
			return (free_table(table, NULL));
	}
	return (false);
}

void	fill_col(t_able *table)
{
	int	i;

	i = -1;
	while (++i < table->tex.draw_start - 1 && table->tex.draw_start < 1250)
		table->mlx.img->addr[(i * WIDTH) + table->col] = table->parse->cclr;
	while (i < table->tex.draw_end)
	{
		table->tex.crd.y = (int)table->tex.pos & (TEXDIM - 1);
		table->tex.pos += table->tex.step;
		table->mlx.img->addr[(i * WIDTH) + table->col] = table->swen_tx \
		[table->ray.side][(TEXDIM * table->tex.crd.y) + table->tex.crd.x];
		i++;
	}
	while (++i < HEIGHT)
		table->mlx.img->addr[((i * WIDTH) + table->col) % 2812500] \
		= table->parse->floor_color;
}

void	texture(t_able *table)
{
	double	wallx;

	if (!table->ray.side || table->ray.side == 2)
		wallx = table->plr.pos.y + table->ray.perp_wall_dist \
		* table->ray.dir.y;
	else
		wallx = table->plr.pos.x + table->ray.perp_wall_dist \
		* table->ray.dir.x;
	wallx -= floor((wallx));
	table->tex.crd.x = wallx * (double)TEXDIM;
	table->tex.step = 1.0 * TEXDIM / table->tex.line_hgt;
	table->tex.pos = (table->tex.draw_start - HEIGHT / 2 + table->tex.line_hgt \
	/ 2) * table->tex.step;
	fill_col(table);
}
