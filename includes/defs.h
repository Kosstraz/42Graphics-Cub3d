/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:54 by ymanchon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/07 14:41:05 by mkhoury          ###   ########.fr       */
=======
/*   Updated: 2024/12/07 16:25:51 by ymanchon         ###   ########.fr       */
>>>>>>> 30ee3555b359368125126130f986f4d4d16c2ac3
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

	//* multi
# define PORT	4243

# define POLL_PLAYER	(char)0
# define POLL_DOOR		(char)1

# define LOCAL		0
# define DISTANT	1

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

# define NB_RAYS		10
# define FOV			60.f
# define DELTA			0
# define PI				3.14159f

# define HITBOX			20.f

# define DEFFREQ_MAX_MULTIPLIER		0.3f
# define DEFFREQ_MAX_PRETTY_OFFSET	3

# define DEFUNIT		8
# define DEFHALFUNIT	4
# define DEFPLAYERSPEED	1.f

	//* constants specifics to cub3d
# define GAME_TITLE		"Alien Isolation"
# define GAME_TITLE_S	"Alien Isolation - Host"
# define MAX_LIFE		100

# define CUB3D_WALL		'1'
# define CUB3D_VOID		'0'
# define CUB3D_DOOR		'P'
# define CUB3D_PLAYER	"NSEW"
# define CUB3D_BLOCKS	"01P "
# define CUB3D_ALL		"01PNSEW "

# define MINIMAP_LAYER	0
# define CAST_LAYER		1

# define BUBBLES_MIN	-18.0f
# define BUBBLES_MID	0.0f
# define BUBBLES_SPEED	60.f
# define BUBBLES_MAX	18.0f

# define C	0
# define F	1

# define NO	0
# define SO	1
# define WE	2
# define EA	3

# define NB_SOUNDS	11
# define AMBIENT	0
# define PRANK		1
# define FREAKY		2
# define STEP1		3
# define STEP2		4
# define STEP3		5
# define STEP4		6
# define STEP5		7
# define DOOR1		8
# define DOOR2		9
# define DOOR3		10

# define TO_OPEN	0
# define TO_CLOSE	1

# define OPEN_DOOR_T	"Ouvrir [E]"
# define CLOSE_DOOR_T	"Fermer [E]"

# define CROUCH_OFFSET	100.0
# define CROUCH_SPEED	250.0f

	//* generic constants
# define TRUE	1
# define FALSE	0
# define BOOL	char
# define BPP	sizeof(int32_t)

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
