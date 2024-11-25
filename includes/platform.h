/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:34:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 15:13:58 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLATFORM_H
# define PLATFORM_H

# include "MLX42-2.4.1/include/MLX42/MLX42.h"
# include "defs.h"

	//* classic typedef
typedef void			(*t_mlx_loopfunc)(void *);
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;



	//* some utilities
typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
}	t_pos;

typedef struct s_posi
{
	int	x;
	int	y;
}	t_posi;

typedef struct s_vector
{
	float	dx;
	float	dy;
	float	dz;
	float	angle;
}	t_vector;

typedef struct s_minmax
{
	int	min;
	int	max;
}	t_minmax;

typedef struct s_color
{
	t_uchar	r;
	t_uchar	g;
	t_uchar	b;
	t_uchar	bytes_wrote;
	BOOL	_overflow;
}	t_color;



	//* CORE
typedef struct s_player
{
	int		life;
	t_pos	position;
	BOOL	crouched;
	t_vector	movement;
	t_vector	view;
}	t_player;

typedef struct s_filepath
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_filepath;

typedef struct s_minimap
{
	t_posi	position;
	t_posi	size;
}	t_minimap;

typedef struct s_map
{
	t_filepath	filepath;
	t_color		cf_colors[2];
	size_t		bufmax;
	size_t		buflens_max;
	size_t		*buflens;
	size_t		buflens_size;
	BOOL		generated;
	char		*file;
	char		**buf;
}	t_map;

typedef struct s_img_container
{
	mlx_image_t	*fps;
	mlx_image_t	*minimap;
}	t_img_container;

typedef struct s_core
{
	t_img_container	imgs;
	mlx_t			*mlx;
	t_player		player;
	t_map			map;
	t_minimap		minimap;
	float			half_width;
	float			half_height;
	BOOL			mouse_visible;
	char			*_strerror;
}	t_core;


	//*	for MAP GENERATION
typedef struct s_gen_config
{
	t_minmax	x;
	t_minmax	y;
	t_minmax	yfreq;
	//t_minmax	xfreq; <-- same than yfreq, can change
	char		spawn1_orientation;
}	t_gen_config;

typedef struct s_gen_utils
{
	size_t	freq_index;
	size_t	freq_val;
	int		average_line_len;
	int		luck_player_spawn_now;
	BOOL	player_has_spawned;
}	t_gen_utils;

typedef struct s_gen_context
{
	t_gen_config	config;
	t_gen_utils		utils;
}	t_gen_context;

#endif
