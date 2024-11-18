#include "cub3d.h"

inline static void	parse_texturefile_path(int fd, t_core *core)
{
	char	*gnl;

	gnl = get_next_line(fd);
	while (gnl)
	{
		if (!ft_strncmp(gnl, "SO", 2))
			core->map.filepath.south = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		else if (!ft_strncmp(gnl, "NO", 2))
			core->map.filepath.north = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		else if (!ft_strncmp(gnl, "EA", 2))
			core->map.filepath.east = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		else if (!ft_strncmp(gnl, "WE", 2))
			core->map.filepath.west = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		free(gnl);
		gnl = get_next_line(fd);
	}
	if (!core->map.filepath.north)
		exit_strerror(NORTH_TEXTURE_FILE_INVALID_T, core);
	else if (!core->map.filepath.south)
		exit_strerror(SOUTH_TEXTURE_FILE_INVALID_T, core);
	else if (!core->map.filepath.east)
		exit_strerror(EAST_TEXTURE_FILE_INVALID_T, core);
	else if (!core->map.filepath.west)
		exit_strerror(WEST_TEXTURE_FILE_INVALID_T, core);
}

inline static void	parse_cf_colors(int fd, t_core *core)
{
	char	*gnl;
	BOOL	cf[2];

	cf[0] = FALSE;
	cf[1] = FALSE;
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (!ft_strncmp(gnl, "C", 1))
		{
			core->map.cf_colors[0] = stocol(ft_strchr_inv(&gnl[1], ' '));
			cf[0] = TRUE;
		}
		else if (!ft_strncmp(gnl, "F", 1))
		{
			core->map.cf_colors[1] = stocol(ft_strchr_inv(&gnl[1], ' '));
			cf[1] = TRUE;
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	if (!cf[0] || core->map.cf_colors[0]._overflow)
		exit_strerror(CEILING_COLOR_FORMAT_INCORRECT_T, core);
	else if (!cf[1] || core->map.cf_colors[1]._overflow)
		exit_strerror(FLOOR_COLOR_FORMAT_INCORRECT_T, core);
}

void	parse_map(t_core *core)
{
	int	fd;

	fd = open(core->map.file, O_RDONLY);
	if (fd == -1)
		exit_strerror(IMPOSSIBLE_TO_OPEN, core);
	parse_texturefile_path(fd, core);
	parse_cf_colors(fd, core);
	close(fd);
}
