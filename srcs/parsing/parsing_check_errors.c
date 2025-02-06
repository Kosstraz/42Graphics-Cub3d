/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:45:45 by mkhoury           #+#    #+#             */
/*   Updated: 2025/02/06 15:21:51 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	parse_texturefile_path_error(t_core *core)
{
	//if (!core->map.filepath.north)
	//	exit_strerror(NORTH_TEXTURE_FILE_INVALID_T, core);
	//else if (!core->map.filepath.south)
	//	exit_strerror(SOUTH_TEXTURE_FILE_INVALID_T, core);
	//else if (!core->map.filepath.east)
	//	exit_strerror(EAST_TEXTURE_FILE_INVALID_T, core);
	//else if (!core->map.filepath.west)
	//	exit_strerror(WEST_TEXTURE_FILE_INVALID_T, core);
	core->xpms[EA] = mlx_load_xpm42(core->map.filepath.east);
	if (!core->xpms[EA])
		printf("error east\n");
	core->xpms[WE] = mlx_load_xpm42(core->map.filepath.west);
	if (!(core->xpms[WE]))
		printf("error west\n");
	core->xpms[SO] = mlx_load_xpm42(core->map.filepath.south);
	if (!core->xpms[SO])
		printf("error south\n");
	core->xpms[NO] = mlx_load_xpm42(core->map.filepath.north);
	if (!core->xpms[NO])
		printf("error north\n");
}

inline void	parse_cf_colors_error(bool cf[2], t_core *core)
{
	if (!cf[0] || core->map.cf_colors[0]._overflow
		|| core->map.cf_colors[0].bytes_wrote != 3)
		exit_strerror(CEILING_COLOR_FORMAT_INCORRECT_T, core);
	else if (!cf[1] || core->map.cf_colors[1]._overflow
		|| core->map.cf_colors[1].bytes_wrote != 3)
		exit_strerror(FLOOR_COLOR_FORMAT_INCORRECT_T, core);
}
