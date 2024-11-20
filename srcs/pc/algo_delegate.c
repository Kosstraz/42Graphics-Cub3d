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

inline void	try_spawn_player(t_gen_context *context, size_t y, size_t x, t_core *core)
{
	if (rand_btw(0, context->utils.luck_player_spawn_now) == 0
		&& !context->utils.player_has_spawned)
	{
		core->map.buf[y][x] = context->config.spawn1_orientation;
		context->utils.player_has_spawned = TRUE;
	}
	else if (y == core->map.bufmax - 2
		&& !context->utils.player_has_spawned)
	{
		core->map.buf[y][x] = context->config.spawn1_orientation;
		context->utils.player_has_spawned = TRUE;
	}
}
