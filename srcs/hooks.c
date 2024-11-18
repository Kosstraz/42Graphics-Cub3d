#include "cub3d.h"

void	cub3d_key_hook(mlx_key_data_t keyd, t_core *core)
{
	if (keyd.action == MLX_PRESS)
	{
		if (keyd.key == MLX_KEY_ESCAPE)
			mlx_close_window(core->mlx);
	}
	else if (keyd.action == MLX_RELEASE)
	{
	}
	else
	{
	}
}

void	cub3d_mouse_hook(mouse_key_t button,
						action_t action,
						modifier_key_t mods,
						t_core *core)
{
	(void)button;
	(void)action;
	(void)mods;
	(void)core;
}

void	cub3d_close_hook(t_core *core)
{
	exit_cub3d(0, core);
}

void	cub3d_cursor_hook(double xpos, double ypos, t_core *core)
{
	(void)xpos;
	(void)ypos;
	(void)core;
}

void	cub3d_scroll_hook(double xdelta, double ydelta, t_core *core)
{
	(void)xdelta;
	(void)ydelta;
	(void)core;
}
