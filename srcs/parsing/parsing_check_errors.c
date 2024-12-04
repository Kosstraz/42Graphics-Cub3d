#include "cub3d.h"

inline void	parse_texturefile_path_error(t_core *core)
{
	if (!core->map.filepath.north)
	{
		exit_strerror(NORTH_TEXTURE_FILE_INVALID_T, core);
		core->xpms[NO] = mlx_load_xpm42(core->map.filepath.north);
	}
	else if (!core->map.filepath.south)
	{
		exit_strerror(SOUTH_TEXTURE_FILE_INVALID_T, core);
		core->xpms[SO] = mlx_load_xpm42(core->map.filepath.south);
	}
	else if (!core->map.filepath.east)
	{
		exit_strerror(EAST_TEXTURE_FILE_INVALID_T, core);
		core->xpms[EA] = mlx_load_xpm42(core->map.filepath.east);
	}
	else if (!core->map.filepath.west)
	{
		exit_strerror(WEST_TEXTURE_FILE_INVALID_T, core);
		core->xpms[WE] = mlx_load_xpm42(core->map.filepath.west);
	}
}

inline void	parse_cf_colors_error(BOOL cf[2], t_core *core)
{
	if (!cf[0] || core->map.cf_colors[0]._overflow
		|| core->map.cf_colors[0].bytes_wrote != 3)
		exit_strerror(CEILING_COLOR_FORMAT_INCORRECT_T, core);
	else if (!cf[1] || core->map.cf_colors[1]._overflow
		|| core->map.cf_colors[1].bytes_wrote != 3)
		exit_strerror(FLOOR_COLOR_FORMAT_INCORRECT_T, core);
}
