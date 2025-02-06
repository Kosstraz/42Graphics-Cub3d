/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:36 by bama              #+#    #+#             */
/*   Updated: 2025/02/05 23:55:52 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static void	parse_texturefile_path(int fd, t_core *core)
//{
//	char	*gnl;
//	int		count;
//
//	count = 0;
//	gnl = get_next_line(fd);
//	while (gnl && count < 4)
//	{
//		if (!ft_strncmp(gnl, "SO", 2))
//			core->map.filepath.south = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
//		else if (!ft_strncmp(gnl, "NO", 2))
//			core->map.filepath.north = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
//		else if (!ft_strncmp(gnl, "EA", 2))
//			core->map.filepath.east = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
//		else if (!ft_strncmp(gnl, "WE", 2))
//			core->map.filepath.west = ft_strdup(ft_strchr_inv(&gnl[2], ' '));
//		if (!ft_strncmp(gnl, "SO", 2) || !ft_strncmp(gnl, "NO", 2)
//			|| !ft_strncmp(gnl, "EA", 2) || !ft_strncmp(gnl, "WE", 2))
//			count++;
//		free(gnl);
//		gnl = get_next_line(fd);
//	}
//}

//static void	parse_cf_colors(
//	bool is_starting,
//	bool cf_b[2],
//	int fd,
//	t_core *core)
//{
//	char	*gnl;
//
//	gnl = get_next_line(fd);
//	while (gnl && (!cf_b[0] || !cf_b[1]))
//	{
//		if (!ft_strncmp(gnl, "C", 1))
//		{
//			core->map.cf_colors[0] = stocol(ft_strchr_inv(&gnl[1], ' '));
//			cf_b[0] = TRUE;
//		}
//		else if (!ft_strncmp(gnl, "F", 1))
//		{
//			core->map.cf_colors[1] = stocol(ft_strchr_inv(&gnl[1], ' '));
//			cf_b[1] = TRUE;
//		}
//		//else if ((!gnl || !gnl[0]) && (!cf_b[0] && !cf_b[1] && !is_starting))
//		//	return ;
//		free(gnl);
//		gnl = get_next_line(fd);
//	}
//}

//void	parse_map(t_core *core)
//{
//	bool	cf[2];
//	int		fd;
//
//	cf[0] = FALSE;
//	cf[1] = FALSE;
//	fd = open(core->map.file, O_RDONLY);
//	if (fd == -1)
//		exit_strerror(IMPOSSIBLE_TO_OPEN, core);
//	parse_cf_colors(TRUE, cf, fd, core);
//	if (!cf[0] && !cf[1])
//	{
//		ft_printf("feur\n");
//		close(fd);
//		fd = open(core->map.file, O_RDONLY);
//		if (fd == -1)
//			exit_strerror(IMPOSSIBLE_TO_OPEN, core);
//	}
//	parse_texturefile_path(fd, core);
//	if (!cf[0] && !cf[1])
//		parse_cf_colors(FALSE, cf, fd, core);
//	parse_texturefile_path_error(core);
//	parse_cf_colors_error(cf, core);
//	parse_asciimap(fd, core);
//	close(fd);
//}

static bool	no_full_file(bool is_here[6])
{
	int	count;
	int	i;

	i = H_NO;
	count = 0;
	while (i <= H_WE)
	{
		if (is_here[i])
			++count;
		++i;
	}
	if (count > 0 && count < 4)
		return (TRUE);
	return (FALSE);
}

static bool	no_full_cf(bool is_here[6])
{
	int	count;

	count = 0;
	count += is_here[H_F];
	count += is_here[H_C];
	if (count > 0 && count < 2)
		return (TRUE);
	return (FALSE);
}

static bool	is_here_is_valid(bool is_here[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!is_here[i])
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static void	parse_settings_cf(bool is_here[6], char *line, t_core *core)
{
	if (!ft_strncmp(line, "C", 1))
	{
		ft_printf("C\n");
		if (no_full_file(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.cf_colors[C] = stocol(ft_strchr_inv(&line[1], ' '));
		is_here[H_C] = TRUE;
	}
	else if (!ft_strncmp(line, "F", 1))
	{
		ft_printf("F\n");
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
		ft_printf("NO\n");
		if (no_full_cf(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.filepath.north = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_NO] = TRUE;
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		ft_printf("SO\n");
		if (no_full_cf(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.filepath.south = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_SO] = TRUE;
	}
	else if (!ft_strncmp(line, "EA", 2))
	{
		ft_printf("EA\n");
		if (no_full_cf(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.filepath.east = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_EA] = TRUE;
	}
	else if (!ft_strncmp(line, "WE", 2))
	{
		ft_printf("WE\n");
		if (no_full_cf(is_here))
			exit_strerror("Bad configuration order.", core);
		core->map.filepath.west = ft_strdup(ft_strchr_inv(&line[2], ' '));
		is_here[H_WE] = TRUE;
	}
}

static void	init_is_here(bool is_here[6])
{
	is_here[0] = FALSE;
	is_here[1] = FALSE;
	is_here[2] = FALSE;
	is_here[3] = FALSE;
	is_here[4] = FALSE;
	is_here[5] = FALSE;
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
	int	fd;

	fd = open(core->map.file, O_RDONLY);
	if (fd == -1)
		exit_strerror(IMPOSSIBLE_TO_OPEN, core);
	parse_settings_map(fd, core);
	parse_asciimap(fd, core);
	close(fd);
}
