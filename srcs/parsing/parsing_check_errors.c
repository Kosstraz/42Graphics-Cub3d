/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:45:45 by mkhoury           #+#    #+#             */
/*   Updated: 2025/02/08 16:43:25 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	parse_texturefile_path_error(t_core *core)
{
	core->xpms[EA] = mlx_load_xpm42(core->map.filepath.east);
	if (!core->xpms[EA])
		exit_strerror("error east texture\n", core);
	core->xpms[WE] = mlx_load_xpm42(core->map.filepath.west);
	if (!(core->xpms[WE]))
		exit_strerror("error west texture\n", core);
	core->xpms[SO] = mlx_load_xpm42(core->map.filepath.south);
	if (!core->xpms[SO])
		exit_strerror("error south texture\n", core);
	core->xpms[NO] = mlx_load_xpm42(core->map.filepath.north);
	if (!core->xpms[NO])
		exit_strerror("error north texture\n", core);
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
