#include "cub3d.h"

inline static void	save_asciimap_handle_memory(int y_pos, t_core *core)
{
	if (y_pos == (int)core->map.bufmax)
	{
		core->map.bufmax = y_pos + 5;
		core->map.buf = (char **)ft_realloc(core->map.buf,
				y_pos * sizeof(char *),
				((y_pos + 5) * sizeof(char *)));
	}
	core->map.buflens = (size_t *)ft_realloc((size_t *)core->map.buflens,
			sizeof(size_t) * core->map.buflens_size,
			sizeof(size_t) * (core->map.buflens_size + 1));
	core->map.buflens_size += 1;
}

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
			save_asciimap_handle_memory(y, core);
			core->map.buf[y] = gnl;
			core->map.buflens[y++] = ft_strlen(gnl);
		}
		else
			free(gnl);
		gnl = get_next_line(fd);
	}
	core->map.buf[y] = NULL;
}

inline static void	parse_asciilines_check_zero(int x, int y, t_core *core)
{
	if (x == 0 || x == (int)core->map.buflens[y])
		exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
	else
	{
		if (core->map.buf[y - 1][x] == ' ')
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (core->map.buf[y + 1][x] == ' ')
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (core->map.buf[y][x + 1] == ' ')
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (core->map.buf[y][x - 1] == ' ')
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
	}
}

static void	parse_asciilines(
	const char *line,
	BOOL *player_spawn,
	int cur,
	t_core *core)
{
	int		i;
	int		linesize;

	i = 0;
	linesize = (int)ft_strlen(line);
	if (line[0] != CUB3D_WALL || line[linesize - 1] != CUB3D_WALL)
		exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
	while (line[i])
	{
		if (cur == 0 && line[i] != ' ' && line[i] != CUB3D_WALL)
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (cur == (int)core->map.bufmax - 1
			&& line[i] != ' '
			&& line[i] != CUB3D_WALL)
			exit_strerror(MAP_PLACE_WITH_NO_WALL_T, core);
		else if (line[i] == CUB3D_VOID)
			parse_asciilines_check_zero(i, cur, core);
		if (!*player_spawn && ft_isanychr(line[i], CUB3D_PLAYER))
		{
			core->player.position.x = i;
			core->player.position.y = cur;
			*player_spawn = TRUE;
		}
		else if (*player_spawn && ft_isanychr(line[i], CUB3D_PLAYER))
			exit_strerror(MAP_PLAYER_REDIFINED_T, core);
		else if (!ft_isanychr(line[i], CUB3D_BLOCKS))
			exit_strerror(MAP_INVALID_CHARACTER_T, core);
		i++;
	}
}

void	parse_asciimap(int fd, t_core *core)
{
	BOOL	player_spawn;
	int		i;

	i = 0;
	player_spawn = FALSE;
	save_asciimap(fd, core);
	core->map.buflens_max = ft_maxul(core->map.buflens, core->map.buflens_size);
	core->map.bufmax = ft_strlen2(core->map.buf);
	while (core->map.buf[i])
	{
		parse_asciilines(core->map.buf[i], &player_spawn, i, core);
		i++;
	}
	if (!player_spawn)
		exit_strerror(MAP_NO_PLAYER_SPAWN_T, core);
}
