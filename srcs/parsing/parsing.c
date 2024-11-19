#include "cub3d.h"

static void	parse_texturefile_path(int fd, t_core *core)
{
	char	*gnl;
	int		count;

	count = 0;
	gnl = get_next_line(fd);
	while (gnl && count < 4)
	{
		if (!ft_strncmp(gnl, "SO", 2))
			core->map.filepath.south = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		else if (!ft_strncmp(gnl, "NO", 2))
			core->map.filepath.north = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		else if (!ft_strncmp(gnl, "EA", 2))
			core->map.filepath.east = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		else if (!ft_strncmp(gnl, "WE", 2))
			core->map.filepath.west = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
		if (!ft_strncmp(gnl, "SO", 2) || !ft_strncmp(gnl, "NO", 2)
			|| !ft_strncmp(gnl, "EA", 2) || !ft_strncmp(gnl, "WE", 2))
			count++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	parse_texturefile_path_error(core);
}

static void	parse_cf_colors(int fd, t_core *core)
{
	char	*gnl;
	BOOL	cf[2];

	cf[0] = FALSE;
	cf[1] = FALSE;
	gnl = get_next_line(fd);
	while (gnl && (!cf[0] || !cf[1]))
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
	parse_cf_colors_error(cf, core);
}

void	parse_map(t_core *core)
{
	int	fd;

	fd = open(core->map.file, O_RDONLY);
	if (fd == -1)
		exit_strerror(IMPOSSIBLE_TO_OPEN, core);
	parse_texturefile_path(fd, core);
	parse_cf_colors(fd, core);
	parse_asciimap(fd, core);
	close(fd);
}
