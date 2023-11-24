/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub69d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:51:27 by aikram            #+#    #+#             */
/*   Updated: 2023/11/24 16:37:00 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB69D_H
# define CUB69D_H

# include <stdint.h>
# include "parse.h"

# define TEXDIM 256
# define MINT "mlx init failed!\n"
# define MWIN "mlx window failed!\n"
# define MIMG "mlx image failed!\n"
# define AIPP "tmp.img memory allocation failed!\n"
# define AIP "tmp.img[] memory allocation failed!\n"
# define MXTI "xpm to img failed!\n"
# define MGDA_SUSO "failed to retrieve data addr!\n"
# define ESCA_TETS "Error\nBasement inhabitant escape attempt!!!"
# define BH "Error\nBlackhole detected!"
# define PALLOC "pad allocation failed!\n"

# ifdef __APPLE__
#  define WIDTH 2250
#  define HEIGHT 1250
# else
#  define WIDTH 1250
#  define HEIGHT 750
# endif

# define DARK_BLUE 0x00000032
# define DARK_BROWN 0x00320000
# define DARK_PRL_PNK 0x006c2545
# define MATURE_GREEN 0x00afb7aa
# define MATURE_SKY 0x00324232

typedef struct s_cords {
	double	x;
	double	y;
}	t_cords;

typedef struct s_img {
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		wdth;
	int		hght;
}	t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_mlx;

typedef struct s_plr {
	t_cords	pos;
	t_cords	dir;
	double	mv_spd;
	double	rt_spd;
}	t_plr;

typedef struct s_texture {
	int					id;
	t_icords			crd;
	size_t				color;
	double				pos;
	double				step;
	int					line_hgt;
	int					draw_start;
	int					draw_end;
	struct s_texture	*poopy;
}	t_rex;

typedef struct s_ray {
	t_cords		dir;
	t_cords		side_dist;
	t_cords		delta_dist;
	t_icords	map;
	t_icords	step;
	int			hit;
	int			side;
	double		perp_wall_dist;
}	t_ray;

typedef struct s_table {
	bool		keys[6];
	bool		destroy;
	char		*swen_pth[4];
	size_t		**swen_tx;
	t_plr		plr;
	t_ray		ray;
	t_rex		tex;
	t_mlx		mlx;
	t_cords		plane;
	t_parse		*parse;
	t_data		*data;
	t_icords	map_max;

	double		camx;
	int			col;
}	t_able;

/* parse_assist */
int		chk_sneaky_space(char **map);

/* parse_assist_ex */
int		padder_pooper(char **map);
int		destroy_and_return(char **pad, int msg);

/* error_handler */
bool	free_table(t_able *table, const char *msg);
int		ultimate_destroyer(t_able *table);
bool	print_and_return(const char *msg);

/* events */
int		main_loop(t_able *table);
int		mouse_hook(t_able *table);
int		handle_keyrelease(int keysym, t_able *table);
int		handle_keypress(int keysym, t_able *table);

/* ray_cast */
void	calc(t_able *table);

/* texture */
void	texture_path_match(t_able *table);
bool	init_texture(t_able *table);
void	texture(t_able *table);

/* window */
void	annihilate_img(t_mlx *mlx_ptr);
t_img	*new_image(t_able *table, bool destroy);

/* execution */
int		eggsecute(t_parse *parse, t_data *data);

/* movement */
void	plyr_rt(t_able *table);
void	plyr_rrt(t_able *table);
void	plyr_mvment(t_able *table, int forward);
void	plyr_strafe(t_able *table, int right);

/* movement_director */
void	plyr_rt_and_mv(t_able *table, int rt, int mv);
void	plyr_rt_and_strf(t_able *table, int rt, int strf);
void	strafe_and_move(t_able *table, int mv, int strf);
void	mv_strf_rt(t_able *table, int mv, int strf, int rt);

/* movement_handler */
bool	handle_movements_util0(t_able *table);
bool	handle_movements_util1(t_able *table);
void	handle_movements(t_able *table);

/* events */
int		handle_keypress(int keysym, t_able *table);
int		handle_keyrelease(int keysym, t_able *table);
int		main_loop(t_able *table);

#endif