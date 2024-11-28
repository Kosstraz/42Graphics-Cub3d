/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:29:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 17:01:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	parse_texturefile_path_error(t_core *core)
{
	if (!core->map.filepath.north)
		exit_strerror(NORTH_TEXTURE_FILE_INVALID_T, core);
	else if (!core->map.filepath.south)
		exit_strerror(SOUTH_TEXTURE_FILE_INVALID_T, core);
	else if (!core->map.filepath.east)
		exit_strerror(EAST_TEXTURE_FILE_INVALID_T, core);
	else if (!core->map.filepath.west)
		exit_strerror(WEST_TEXTURE_FILE_INVALID_T, core);
}

inline void	parse_cf_colors_error(BOOL cf[2], t_core *core)
{
	if (!cf[C] || core->map.cf_colors[C]._overflow
		|| core->map.cf_colors[C].bytes_wrote != 3)
		exit_strerror(CEILING_COLOR_FORMAT_INCORRECT_T, core);
	else if (!cf[F] || core->map.cf_colors[F]._overflow
		|| core->map.cf_colors[F].bytes_wrote != 3)
		exit_strerror(FLOOR_COLOR_FORMAT_INCORRECT_T, core);
}
