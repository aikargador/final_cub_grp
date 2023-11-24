/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:00:10 by aikram            #+#    #+#             */
/*   Updated: 2023/11/22 11:52:44 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define WALL_ERR "MAP_NOT_SURROUNDED_BY_WALLS"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_EXIT 17

// keys
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

enum e_tex_idx
{
	NORTH = 0,
	SOUTH,
	EAST,
	WEST
};

enum e_out
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BR = 3,
	CONTINUE = 4
};

typedef struct s_icords {
	int	x;
	int	y;
}			t_icords;

typedef struct s_imap
{
	int		fd;
	int		line_count;
	char	*path;
	char	**file;
	int		height;
	int		width;
	int		end_idx;
}	t_imap;

typedef struct s_parse
{
	t_icords		pos;
	char			**map;
	int				num_lines;
	char			**text;
	char			*no_text;
	char			*so_text;
	char			*we_text;
	char			*ea_text;
	unsigned int	floor_color;
	unsigned int	cclr;
	size_t			column;
	size_t			row;
	int				*floor;
	int				*ceiling;
	char			pdir;
	t_imap			imap;
}	t_parse;

typedef struct s_data
{
	t_parse			*parse;
	double			angle_increment;
	unsigned int	**buffer;
	int				previous;
}	t_data;

bool	chk_valid_file(char *str, char *type);
bool	chk_cub_and_xmp(char *str, bool cub);

void	set_plr_pos(t_parse *parse, char **map, int y, int x);
void	free_parser(t_parse *parse);
void	free_memory(t_parse *parse, t_data *data);
void	free_double_array(char ***str);
void	free_double_array2(unsigned int ***str);
int		print_err(char *info, char *str, int code);
void	initialize_imap(t_imap *inputmap);
void	void_free_arr(void **str);
int		ft_parse(t_parse *parse, char *path);
int		print_err_val(int detail, char *str, int code);
void	parse_map_file(char *path, t_parse *parse);
int		fill_dir_tex(t_parse *parse, char *line, int j);
int		fill_color_textures(t_parse *parse, char *line, int j);
int		check_map_ifvalid(t_parse *parse, char **map);
int		check_mapfile(char *arg, bool cub);
int		check_texture(t_parse *parse);
int		get_map(t_parse *parse, char **map);
int		check_map_elements(t_parse *parse, char **map_tab);
int		check_map_is_at_the_end(t_imap *map);
int		create_map(t_parse *parse, char **file, int i);
int		check_wall_elements(t_parse *p, int j, int i, int start);
int		is_start_zero(char **map, int j);
int		check_front(char **map, int j, int i);
int		check_wall_elements_2(t_parse *p, int j, int i, int start);
void	initialize_parse_vars(t_parse *parse);
void	duplicate_parse(t_parse *parse);
int		check_walls(t_parse *p, int j, int i);

#endif