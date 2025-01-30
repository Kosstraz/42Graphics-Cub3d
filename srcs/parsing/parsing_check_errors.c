/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:45:45 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/27 18:53:27 by bama             ###   ########.fr       */
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
	core->xpms = malloc (sizeof(xpm_t*) * 4);
	if (!core->xpms)
		exit(1);
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

	// printf("path west %p\n", core->xpms[NO]);
	// printf("path east %p\n", core->xpms[SO]);
	// printf("path sud %p\n", core->xpms[EA]);
	// printf("path nord %p\n", core->xpms[WE]);
	// int i = 0;
	// while (1)
	// {
	// 	printf("color is i %i  %x\n", i, (unsigned int)core->xpms[NO]->texture.pixels[i]);
	// 	i++;
	// }
	// else
	// 	core->xpms[WE] = mlx_load_xpm42(core->map.filepath.west);

inline void	parse_cf_colors_error(BOOL cf[2], t_core *core)
{
	if (!cf[0] || core->map.cf_colors[0]._overflow
		|| core->map.cf_colors[0].bytes_wrote != 3)
		exit_strerror(CEILING_COLOR_FORMAT_INCORRECT_T, core);
	else if (!cf[1] || core->map.cf_colors[1]._overflow
		|| core->map.cf_colors[1].bytes_wrote != 3)
		exit_strerror(FLOOR_COLOR_FORMAT_INCORRECT_T, core);
}
