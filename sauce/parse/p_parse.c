/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:48:01 by aikram            #+#    #+#             */
/*   Updated: 2023/11/24 22:26:21 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	chk_valid_file(char *str, char *type)
{
	bool	dir_chk;

	dir_chk = false;
	if (!ft_strncmp("./", str, 2))
		str += 2;
	else if (!ft_strncmp("~/", str, 2))
		str += 2;
	else if (!ft_strncmp("../", str, 3))
		str += 3;
	while (*str && ((*str >= 'a' && *str <= 'z') || (*str >= 'A' \
	&& *str <= 'Z') || *str == '_' || (*str >= '0' && *str <= '9') \
	|| *str == '/' || !ft_strcmp("../", str)))
	{
		if (dir_chk && *str == '/')
			return (true);
		dir_chk = false;
		if (*str == '/' || !ft_strcmp("../", str))
			dir_chk = true;
		str++;
	}
	if (dir_chk)
		return (true);
	return (ft_strcmp(type, str));
}

bool	chk_cub_and_xmp(char *str, bool cub)
{
	if (cub)
	{
		if (chk_valid_file(str, ".cub"))
			return (print_err(str, "not a .cub file", 1));
	}
	else if (chk_valid_file(str, ".xpm"))
		return (print_err(str, "not a .xpm file", 1));
	return (false);
}

static bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

int	check_mapfile(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (print_err(arg, "is Directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (print_err(arg, strerror(errno), 1));
	close(fd);
	if (chk_cub_and_xmp(arg, cub))
		return (1);
	return (0);
}

int	ft_parse(t_parse *parse, char *path)
{
	if (check_mapfile(path, true) == 1)
		return (SUCCESS);
	parse->pdir = '\0';
	initialize_imap(&parse->imap);
	parse_map_file(path, parse);
	if (parse->imap.file == NULL)
		return (SUCCESS);
	initialize_parse_vars(parse);
	if (get_map(parse, parse->imap.file) == 1)
		return (free_double_array(&parse->imap.file), 0);
	if (check_map_ifvalid(parse, parse->map) == FAILURE)
		return (free_parser(parse), 0); 
	if (check_texture(parse) == FAILURE)
		return (free_parser(parse), 0);
	duplicate_parse(parse);
	return (1);
}
