/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:34:32 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/05 21:54:16 by bama             ###   ########.fr       */
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
typedef struct s_cmpt
{
	int	i;
	int	j;
}	t_cmpt;

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
	bool	_overflow;
}	t_color;

typedef struct s_casting
{
	float		casts[1920];
	float		angle[1920];
//	float		line_height[1920];
	t_pos		wall[1920];
	int			side[1920];
	int			height[1920];
	float		wallx[1920];
	float		wall_dist[1920];
	bool		is_door;
	float		di;
	int			hfov;
	t_pos		last_pose;
	t_vector	last_view;
	int			last_width;
}	t_casting;

typedef struct s_face
{
	int		side;
	long	texture[12][8];
	float	angle1;
	float	angle2;
	float	length1;
	float	length2;		
}	t_face;

typedef struct s_component
{
	t_pos	points[4];
	float	angle[4];
	float	distance[4];
	int		texture[4][8][12];
}	t_component;

typedef struct s_entity
{
	t_pos		position;
	t_component	corps;
	t_vector	view;
}	t_entity;

	//* NETWORKING
typedef struct s_tcp
{
	struct sockaddr_in	sock;
	int					fd;
	int					com;
}	t_tcp;

typedef struct s_network
{
	bool	is_active;
	bool	is_host;
	t_tcp	tcp;
}	t_network;

	//* CORE
typedef struct s_player
{
	int			life;
	float		speed;
	float		offset;
	t_pos		position;
	bool		crouched;
	t_vector	movement;
	t_vector	view;
	float		bubbles;
	float		bubbles_speed;
	bool		maxed;
	bool		mined;
	bool		torch_activated;
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

typedef struct s_door
{
	t_posi	pos;
	bool	is_open;
}	t_door;

typedef struct s_door_info
{
	int		which_door;
	bool	is_open;
}	t_door_info;

typedef struct s_map
{
	t_filepath	filepath;
	t_color		cf_colors[2];
	size_t		bufmax;
	size_t		buflens_max;
	size_t		*buflens;
	size_t		buflens_size;
	size_t		bufsize;
	t_door		*doors;
	size_t		nb_of_doors;
	bool		generated;
	char		*file;
	char		**buf;
}	t_map;

typedef struct s_img_container
{
	mlx_image_t	*fps;
	mlx_image_t	*minimap;
	mlx_image_t	*cast;
}	t_img_container;

typedef struct s_layer
{
	uint32_t	***pixels;
	uint32_t	height;
	uint32_t	width;
}	t_layer;

typedef struct s_utils
{
	mlx_image_t	*door_text[2];
	int			door_focus;
	int			door_offset;
	int			door_init_offset;
	bool		door_begin;
}	t_utils;

typedef struct s_input_action
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	key_right;
	bool	key_left;
	bool	key_up;
	bool	key_down;
	bool	key_shift;
}	t_input_action;

typedef struct s_audio
{
	uint8_t			*buffer;
	uint8_t			*pos;
	uint32_t		len;
	uint32_t		start_len;
	bool			is_active;
}	t_audio;

typedef struct s_core
{
	t_audio			audio[NB_SOUNDS];
	SDL_AudioSpec	*spec;
	t_img_container	imgs;
	mlx_t			*mlx;
	t_player		player[2];
	t_layer			layer[2];
	t_input_action	input_action;
	t_map			map;
	t_minimap		minimap;
	t_network		network;
	t_casting		cast;
	t_utils			utils;
	xpm_t			*xpms[4];
	float			half_width;
	float			half_height;
	bool			mouse_visible;
	int				fps_cooldown;
	char			*_strerror;
	int				tex_debug;
	mlx_texture_t	*texturej;
}	t_core;

typedef struct s_core_audio
{
	t_core		*core;
	t_audio		*audio;
	ssize_t		i;
	int			to_copy;
	t_posi		len_index;
}	t_core_audio;

	//*	for MAP GENERATION
typedef struct s_gen_config
{
	t_minmax	x;
	t_minmax	y;
	t_minmax	yfreq;
	//t_minmax	xfreq; <-- same than yfreq, can change
	char		spawn1_orientation;
	char		spawn2_orientation;
}	t_gen_config;

typedef struct s_gen_utils
{
	size_t	freq_index;
	size_t	freq_val;
	int		average_line_len;
	int		luck_player_spawn_now;
	bool	player1_has_spawned;
	bool	player2_has_spawned;
}	t_gen_utils;

typedef struct s_gen_context
{
	t_gen_config	config;
	t_gen_utils		utils;
}	t_gen_context;

typedef struct s_ivector
{
	int	x;
	int	y;
	int	z;
}	t_ivector;

typedef struct s_fvector
{
	float	x;
	float	y;
	float	z;
}	t_fvector;

typedef struct s_raycast
{
	t_fvector	unit;
	t_fvector	vector_dir;
	t_ivector	step;
	t_fvector	side;
	t_fvector	ray_start;
	t_ivector	map_check;
	float		distance;
	int			side_int;
	double		walldist;
	float		wall_x;
}	t_raycast;

typedef struct s_col
{
	int		i;
	int		y;
	long	col;
	float	nb_pixels;
	int		torchx;
	float	torchlength;
	float	half_nb_pixels;
}	t_col;

#endif
