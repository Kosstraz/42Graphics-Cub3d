/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asciimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:39:09 by bama              #+#    #+#             */
/*   Updated: 2025/02/10 18:38:20 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	save_asciimap_handle_memory(
	char *gnl,
	int y_pos,
	t_core *core)
{
	if (y_pos == (int)core->map.bufmax)
	{
		core->map.bufmax = y_pos + 5;
		core->map.buf = (char **)ft_realloc(core->map.buf,
				y_pos * sizeof(char *),
				((y_pos + 5 + 1) * sizeof(char *)));
	}
	core->map.buflens = (size_t *)ft_realloc((size_t *)core->map.buflens,
			sizeof(size_t) * core->map.buflens_size,
			sizeof(size_t) * (core->map.buflens_size + 1));
	core->map.buflens_size += 1;
	core->map.bufsize = y_pos + 1;
	core->map.buf[y_pos] = ft_strdup(gnl);
	core->map.buflens[y_pos] = ft_strlen(gnl);
}

char	*skip_first_void_lines(int fd);

static void	save_asciimap(int fd, t_core *core)
{
	char	*gnl;
	int		y;
	bool	void_line;

	y = 0;
	void_line = FALSE;
	gnl = skip_first_void_lines(fd);
	while (gnl)
	{
		if (gnl[0] != '\0')
		{
			save_asciimap_handle_memory(gnl, y++, core);
			if (void_line)
				exit_strerror("Map separee en deux parties.\n", core);
		}
		else
			void_line = TRUE;
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	core->map.bufsize = y;
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
	bool players_spawn[2],
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
		parse_asciilines2(line, players_spawn, (int []){i, cur}, core);
		i++;
	}
}

void	parse_asciimap(int fd, t_core *core)
{
	bool	players_spawn[2];
	int		i;

	i = 0;
	players_spawn[LOCAL] = FALSE;
	players_spawn[DISTANT] = FALSE;
	save_asciimap(fd, core);
	if (!core->map.buflens || core->map.buflens_size <= 0)
		exit_strerror("No map in map file.\n", core);
	core->map.buflens_max = ft_maxul(core->map.buflens, core->map.buflens_size);
	core->map.bufmax = ft_strlen2(core->map.buf);
	while (core->map.buf[i])
	{
		parse_asciilines(core->map.buf[i], players_spawn, i, core);
		i++;
	}
	if (!players_spawn[LOCAL])
		exit_strerror(MAP_NO_PLAYER_SPAWN_T, core);
	else if (core->network.is_active && !players_spawn[DISTANT])
		exit_strerror(MAP_NO_PLAYER_SPAWN_T, core);
}
