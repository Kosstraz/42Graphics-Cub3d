#include "cub3d.h"

static void	save_asciimap(int fd, t_core *core)
{
	char	*gnl;
	int		y;

	y = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (gnl[0] != '\0')
		{
			if (y == (int)core->map.bufmax)
			{
				core->map.bufmax = y + 5;
				core->map.buf = (char **)ft_realloc(core->map.buf,
						y * sizeof(char *),
						((y + 5) * sizeof(char *)));
			}
			core->map.buf[y++] = gnl;
		}
		else
			free(gnl);
		gnl = get_next_line(fd);
	}
	core->map.buf[y] = NULL;
}

static void	parse_asciiinternline(const char c, int x, int y, t_core *core)
{
	
}

static void	parse_asciilines(const char *line, int cur, t_core *core)
{
	int		i;
	int		linesize;

	linesize = (int)ft_strlen(line);
	i = 0;
	if (line[0] != CUB3D_WALL || line[linesize - 1] != CUB3D_WALL)
		exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
	while (line[i])
	{
		if (cur == 0 && line[i] != ' ' && line[i] != CUB3D_WALL)
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (cur == core->map.bufmax - 1
			&& line[i] != ' '
			&& line[i] != CUB3D_WALL)
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (line[i] != ' ' && line[i] != '\n')
			parse_asciiinternline(line[i], i, cur, core);
		i++;
	}
}

void	parse_asciimap(int fd, t_core *core)
{
	int	i;

	i = 0;
	save_asciimap(fd, core);
	core->map.bufmax = ft_strlen2(core->map.buf);
	while (core->map.buf[i])
	{
		parse_asciilines(core->map.buf[i], i, core);
		i++;
	}
}
