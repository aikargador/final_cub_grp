/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:47:53 by aikram            #+#    #+#             */
/*   Updated: 2023/11/19 18:47:54 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	initialize_imap(t_imap *inputmap)
{
	inputmap->fd = 0;
	inputmap->line_count = 0;
	inputmap->path = NULL;
	inputmap->file = NULL;
	inputmap->height = 0;
	inputmap->width = 0;
	inputmap->end_idx = 0;
}

void	duplicate_parse(t_parse *parse)
{
	parse->num_lines = parse->imap.line_count;
	parse->text = parse->imap.file;
	parse->column = parse->imap.width;
	parse->row = parse->imap.height;
}

void	initialize_parse_vars(t_parse *parse)
{
	parse->no_text = NULL;
	parse->so_text = NULL;
	parse->we_text = NULL;
	parse->ea_text = NULL;
	parse->map = NULL;
	parse->floor = 0;
	parse->ceiling = 0;
}
