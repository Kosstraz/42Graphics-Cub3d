/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:27:50 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calcul_next_frequence(t_gen_context *context, size_t y, t_core core)
{
	if (context->config.yfreq.max <= (int)(core.map.bufmax - y))
		context->utils.freq_val = rand_btw(context->config.yfreq.min,
				context->config.yfreq.max);
	else
		context->utils.freq_val = core.map.bufmax;
	context->utils.freq_index = 0;
}

static void	deduction_of_xline_size(
	t_gen_context context,
	size_t y,
	t_core *core)
{
	core->map.buflens = (size_t *)ft_realloc(core->map.buflens,
			core->map.buflens_size * sizeof(size_t),
			(core->map.buflens_size + 1) * sizeof(size_t));
	core->map.buflens_size += 1;
	if (y == 0)
		core->map.buflens[y] = rand_btw(context.config.x.min,
				context.config.y.max);
	else if (y == core->map.bufmax - 1)
		core->map.buflens[y] = core->map.buflens[y - 1];
	else
	{
		if (context.utils.freq_index == context.utils.freq_val)
			calcul_next_frequence(&context, y, *core);
		if (context.utils.freq_index == 0)
			core->map.buflens[y] = rand_btw(context.config.x.min,
					context.config.x.max);
		else
			core->map.buflens[y] = core->map.buflens[y - 1];
		++context.utils.freq_index;
	}
	core->map.buf[y] = (char *)malloc(sizeof(char)
			* (core->map.buflens[y] + 2));
	core->map.buf[y][core->map.buflens[y]] = '\n';
	core->map.buf[y][core->map.buflens[y] + 1] = '\0';
}

static void	generate_xline(t_gen_context *context, size_t y, t_core *core)
{
	size_t	x;

	x = 0;
	while (x < core->map.buflens[y])
	{
		if (put_outline_walls(x, y, core) == CUB3D_VOID)
		{
			try_spawn_player(context, y, x, core);
			fill_line(context, x, y, core);
		}
		++x;
	}
	//try_shift_line(context, y, core);
	--context->utils.luck_player_spawn_now;
}

static void	put_last_walls(size_t y, t_core *core)
{
	size_t	x;

	x = 1;
	while (x < core->map.buflens[y] - 1)
	{
		//if (core->map.buf[y][x] == CUB3D_VOID)
		//{
			if (x <= core->map.buflens[y - 1] && core->map.buf[y - 1][x] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (x <= core->map.buflens[y + 1] && core->map.buf[y + 1][x] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (core->map.buf[y][x + 1] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (core->map.buf[y][x - 1] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (x <= core->map.buflens[y - 1] && core->map.buf[y - 1][x + 1] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (x <= core->map.buflens[y - 1] && core->map.buf[y - 1][x - 1] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (x <= core->map.buflens[y + 1] && core->map.buf[y + 1][x + 1] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (x <= core->map.buflens[y + 1] && core->map.buf[y + 1][x - 1] == ' ')
				core->map.buf[y][x] = CUB3D_WALL;
			else if (core->map.buf[y][x] == CUB3D_VOID)
			{
				if (x >= core->map.buflens[y - 1])
					core->map.buf[y][x] = CUB3D_WALL;
				if (x >= core->map.buflens[y + 1])
					core->map.buf[y][x] = CUB3D_WALL;
			}
		//}
		++x;
	}
}

void	generate(t_gen_context *context, t_core *core)
{
	size_t	y;

	y = 0;
	while (y < core->map.bufmax)
		deduction_of_xline_size(*context, y++, core);
	y = 0;
	while (y < core->map.buflens_size)
		context->utils.average_line_len += core->map.buflens[y++];
	context->utils.average_line_len /= core->map.buflens_size * 1.0f;
	y = 0;
	while (y < core->map.bufmax)
		generate_xline(context, y++, core);
	y = 1;
	while (y < core->map.bufmax - 1)
		put_last_walls(y++, core);
}
