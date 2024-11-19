/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:34:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/19 19:35:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLATFORM_H
# define PLATFORM_H

# include "MLX42-2.4.1/include/MLX42/MLX42.h"
# include "defs.h"

typedef void			(*t_mlx_loopfunc)(void *);
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_player
{
	int		life;
	t_pos	position;
	BOOL	crouched;
}	t_player;

typedef struct s_color
{
	t_uchar	r;
	t_uchar	g;
	t_uchar	b;
	BOOL	_overflow;
}	t_color;

typedef struct s_filepath
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_filepath;

typedef struct s_map
{
	t_filepath	filepath;
	t_color		cf_colors[2];
	size_t		bufmax;
	size_t		*buflens;
	size_t		buflens_size;
	char		*file;
	char		**buf;
}	t_map;

typedef struct s_core
{
	mlx_t		*mlx;
	t_player	player;
	t_map		map;
	float		half_width;
	float		half_height;
	BOOL		mouse_visible;
	char		*_strerror;
}	t_core;

#endif
