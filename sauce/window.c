/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:02:46 by aikram            #+#    #+#             */
/*   Updated: 2023/11/20 21:14:54 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

void	annihilate_img(t_mlx *mlx_ptr)
{
	if (mlx_ptr->img)
	{
		if (mlx_ptr->img->img)
			mlx_destroy_image(mlx_ptr, mlx_ptr->img->img);
		free(mlx_ptr->img);
		mlx_ptr->img = NULL;
	}
}

t_img	*new_image(t_able *table, bool destroy)
{
	t_img	*img;

	if (destroy)
		annihilate_img(&table->mlx);
	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(&table->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (NULL);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, \
			&img->line_len, &img->endian);
	if (!img->addr)
		return (NULL);
	return (img);
}
