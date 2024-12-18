/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:34:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/10 18:23:30 by mkhoury          ###   ########.fr       */
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

typedef struct s_casting
{
	float		casts[1920];
	float		angle[1920];
//	float		line_height[1920];
	t_pos		wall[1920];
	int			side[1920];
	int			height[1920];
	float		wallx[1920];
	float		wallDist[1920];
	BOOL		is_door;
	float		max;
	float		min;
	float		di;
	int			hfov;
	t_pos		last_pose;
	t_vector	last_view;
	int			last_width;
}	t_casting;

typedef struct	s_face
{
	t_pos			*p1;
	t_pos			*p2;
	t_pos			*p3;
	t_pos			*p4;
	int				index[4];
	mlx_texture_t	*texture;
	t_ipos			offset;	
} t_face;

typedef	struct s_component
{
	t_pos	points[8];
	float	angle[4];
	float	distance[4];
	t_face	face[6];
}	t_component;

typedef struct s_player_entity
{
	t_component		corps;
	t_component		head;
	t_component		left_arm;
	t_component		right_arm;
	t_component		left_leg;
	t_component		right_leg;
	mlx_texture_t	*texture;
}	t_player_entity;

// typedef struct s_3points
// {
// 	/* data */
// }	t_3points;

	//* NETWORKING
typedef struct s_tcp
{
	struct sockaddr_in	sock;
	int					fd;
	int					com;
}	t_tcp;

typedef struct s_network
{
	BOOL	is_active;
	BOOL	is_host;
	t_tcp	tcp;
}	t_network;


	//* CORE
typedef struct s_player
{
	int				life;
	float			speed;
	float			offset;
	t_pos			position;
	BOOL			crouched;
	t_vector		movement;
	t_vector		view;
	t_player_entity	entity;
	float			bubbles;
	float			bubbles_speed;
	BOOL			maxed;
	BOOL			mined;
	BOOL			torch_activated;
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
	BOOL	is_open;
}	t_door;

typedef struct s_door_info
{
	int		which_door;
	BOOL	is_open;
}	t_door_info;

typedef struct s_map
{
	t_filepath	filepath;
	t_color		cf_colors[2];
	size_t		bufmax;
	size_t		buflens_max;
	size_t		*buflens;
	size_t		buflens_size;
	t_door		*doors;
	size_t		nbOfDoors;
	BOOL		generated;
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
	BOOL		door_begin;
}	t_utils;

typedef struct s_input_action
{
	BOOL	key_w;
	BOOL	key_a;
	BOOL	key_s;
	BOOL	key_d;
	BOOL	key_right;
	BOOL	key_left;
	BOOL	key_up;
	BOOL	key_down;
	BOOL	key_shift;
}	t_input_action;

typedef struct s_audio
{
	uint8_t			*buffer;
	uint8_t			*pos;
	uint32_t		len;
	uint32_t		start_len;
	BOOL			is_active;
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
	xpm_t			**xpms;
	mlx_texture_t	*entity[2];
	float			half_width;
	float			half_height;
	BOOL			mouse_visible;
	int				fps_cooldown;
	char			*_strerror;
	int	tex_debug;
}	t_core;


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
	BOOL	player1_has_spawned;
	BOOL	player2_has_spawned;
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

typedef struct s_ipos
{
	int	x;
	int	y;
}	t_ipos;

#endif
