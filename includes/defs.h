/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:54 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 18:38:03 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

	//* multi
# define PORT	4243

	//*	default values
# define DEFWIDTH	800
# define DEFHEIGHT	600
# define DEFMAPBUF	5

# define DEFMAPX_MIN	15
# define DEFMAPX_MAX	30
# define DEFMAPY_MIN	10
# define DEFMAPY_MAX	20
# define DEFFREQ_MIN	3

# define DEFLUCK		20

# define DEFFREQ_MAX_MULTIPLIER		0.3f
# define DEFFREQ_MAX_PRETTY_OFFSET	3

# define DEFUNIT		8
# define DEFHALFUNIT	4
# define DEFPLAYERSPEED	0.1f

	//* constants specifics to cub3d
# define GAME_TITLE		"Alien Isolation"
# define MAX_LIFE		100
# define CROUCH_OFFSET	//{inserer int}

# define CUB3D_WALL		'1'
# define CUB3D_VOID		'0'
# define CUB3D_PLAYER	"NSEW"
# define CUB3D_BLOCKS	"01 "

	//* generic constants
# define TRUE	1
# define FALSE	0
# define BOOL	char

	//* error constants
# define CONCEDE_MAP	"Please concede map .cub in program argument\n"

# define PARSING_ERROR_T	"Error\n"

# define BAD_EXTENSION_FILE_T	"Bad extension file, please put a .cub file\n"
# define IMPOSSIBLE_TO_OPEN		"Impossible to open file\n"

# define NORTH_TEXTURE_FILE_INVALID_T	"North texture file is invalid\n"
# define SOUTH_TEXTURE_FILE_INVALID_T	"South texture file is invalid\n"
# define EAST_TEXTURE_FILE_INVALID_T	"East texture file is invalid\n"
# define WEST_TEXTURE_FILE_INVALID_T	"West texture file is invalid\n"

# define CEILING_COLOR_FORMAT_INCORRECT_T	"Ceiling color format is incorrect\n"
# define FLOOR_COLOR_FORMAT_INCORRECT_T		"Floor color format is incorrect\n"

# define MAP_NO_PLAYER_SPAWN_T		"There is no player spawn\n"
# define MAP_PLAYER_REDIFINED_T		"The player has been redefined\n"
# define MAP_PLACE_WITH_NO_WALL_T	"A place with no wall exist\n"
# define MAP_UNKNOW_SYMBOL_T		"An unknow symbol is on the map config\n"
# define MAP_INVALID_CHARACTER_T	"An invalid character is on the map .cub\n"

# define FILE_BAD_EXTENSION_T "Please let a \"*.cub\" file\n"
# define FILE_CONFIGURATION_T "Maybe review order of the .cub configuration\n"

#endif
