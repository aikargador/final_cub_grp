/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:22 by aikram            #+#    #+#             */
/*   Updated: 2023/11/22 12:36:41 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

bool	print_and_return(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (false);
}

bool	free_table(t_able *table, const char *msg)
{
	int	i;

	i = -1;
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	(void)table;
	if (table->mlx.win)
		mlx_destroy_window(table->mlx.mlx, table->mlx.win);
	if (table->mlx.img)
		free(table->mlx.img);
	if (table->mlx.mlx)
		free(table->mlx.mlx);
	while (++i < 4 && table->swen_tx)
		free(table->swen_tx[i]);
	if (table->swen_tx)
		free(table->swen_tx);
	return (69);
}

int	ultimate_destroyer(t_able *table)
{
	free_table(table, NULL);
	free_memory(table->parse, table->data);
	return (0);
}
