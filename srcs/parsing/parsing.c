/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:36 by bama              #+#    #+#             */
/*   Updated: 2025/02/07 13:36:25 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	no_full_file(bool is_here[6]);
bool	no_full_cf(bool is_here[6]);
bool	is_here_is_valid(bool is_here[6]);
void	init_is_here(bool is_here[6]);

static void	parse_settings_cf(bool is_here[6], char *line, t_core *core)
{
	if (!ft_strncmp(line, "C", 1))
	{
		if (no_full_file(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.cf_colors[C] = stocol(ft_strchr_inv(&line[1], ' '));
		is_here[H_C] = TRUE;
	}
	else if (!ft_strncmp(line, "F", 1))
	{
		if (no_full_file(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.cf_colors[F] = stocol(ft_strchr_inv(&line[1], ' '));
		is_here[H_F] = TRUE;
	}
}

static void	parse_settings_file(bool is_here[6], char *line, t_core *core)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		core->map.filepath.north = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_NO] = TRUE;
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		core->map.filepath.south = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_SO] = TRUE;
	}
	else if (!ft_strncmp(line, "EA", 2))
	{
		core->map.filepath.east = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_EA] = TRUE;
	}
	else if (!ft_strncmp(line, "WE", 2))
	{
		core->map.filepath.west = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_WE] = TRUE;
	}
	if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2))
		&& no_full_cf(is_here))
		exit_strerror("Bad configuration order.", core);
}

static void	parse_settings_map(int fd, t_core *core)
{
	bool	is_here[6];
	char	*line;

	init_is_here(is_here);
	line = get_next_line(fd);
	while (line)
	{
		parse_settings_file(is_here, line, core);
		parse_settings_cf(is_here, line, core);
		if (is_here_is_valid(is_here))
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!is_here_is_valid(is_here))
		exit_strerror("Bad settings in map file.", core);
}

void	parse_map(t_core *core)
{
	int		fd;

	fd = open(core->map.file, O_RDONLY);
	if (fd == -1)
		exit_strerror(IMPOSSIBLE_TO_OPEN, core);
	parse_settings_map(fd, core);
	send(core->network.tcp.com, core->map.cf_colors, sizeof(t_color) * 2, 0);
	parse_asciimap(fd, core);
	parse_texturefile_path_error(core);
	close(fd);
}
