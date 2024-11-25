/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_delegate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:37 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 19:22:49 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	put_outline_walls(size_t x, size_t y, t_core *core)
{
	if (y == 0 || y == core->map.bufmax - 1)
		core->map.buf[y][x] = CUB3D_WALL;
	else if (x == 0 || x == core->map.buflens[y] - 1)
		core->map.buf[y][x] = CUB3D_WALL;
	else if (core->map.buflens[y - 1] < core->map.buflens[y]
		&& x >= core->map.buflens[y - 1])
		core->map.buf[y][x] = CUB3D_WALL;
	else if (core->map.buflens[y + 1] < core->map.buflens[y]
		&& x >= core->map.buflens[y + 1])
		core->map.buf[y][x] = CUB3D_WALL;
	else
		core->map.buf[y][x] = CUB3D_VOID;
	if (core->map.buf[y][x] == CUB3D_WALL)
		return (CUB3D_WALL);
	return (CUB3D_VOID);
}

inline void	try_spawn_player2(
	t_gen_context *context,
	size_t y,
	size_t x,
	t_core *core)
{
	if (rand_btw(0, context->utils.luck_player_spawn_now) == 0
		&& !context->utils.player2_has_spawned)
	{
		core->map.buf[y][x] = context->config.spawn2_orientation;
		context->utils.player2_has_spawned = TRUE;
		core->player[1].position.x = x;
		core->player[1].position.y = y;
	}
	else if (y == core->map.bufmax - 2
		&& !context->utils.player2_has_spawned)
	{
		core->map.buf[y][x] = context->config.spawn2_orientation;
		context->utils.player2_has_spawned = TRUE;
		core->player[1].position.x = x;
		core->player[1].position.y = y;
	}
}

inline void	try_spawn_player(
	t_gen_context *context,
	size_t y,
	size_t x,
	t_core *core)
{
	if (rand_btw(0, context->utils.luck_player_spawn_now) == 0
		&& !context->utils.player1_has_spawned)
	{
		core->map.buf[y][x] = context->config.spawn1_orientation;
		context->utils.player1_has_spawned = TRUE;
		core->player[0].position.x = x;
		core->player[0].position.y = y;
	}
	else if (y == core->map.bufmax - 2
		&& !context->utils.player1_has_spawned)
	{
		core->map.buf[y][x] = context->config.spawn1_orientation;
		context->utils.player1_has_spawned = TRUE;
		core->player[0].position.x = x;
		core->player[0].position.y = y;
	}
	else if (core->multi.is_active)
		try_spawn_player2(context, y, x, core);
}

inline void	try_shift_line(t_gen_context *context, size_t y, t_core *core)
{
	char	*tmp;
	size_t	nb_of_spaces;
	size_t	i;

	if (core->map.buflens[y] < (size_t)context->utils.average_line_len)
	{
		nb_of_spaces = rand_btw(
				core->map.buflens[y],
				context->utils.average_line_len);
		i = 0;
		nb_of_spaces /= 3;
		tmp = NULL;
		while (i < nb_of_spaces)
		{
			tmp = ft_strfjoin(tmp, " ");
			i++;
		}
		core->map.buflens[y] += ft_strlen(tmp);
		core->map.buf[y] = ft_strffjoin(tmp, core->map.buf[y]);
	}
}

void	fill_line(t_gen_context *context, size_t x, size_t y, t_core *core)
{
	(void)context;
	(void)x;
	(void)y;
	(void)core;
}
