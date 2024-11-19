#include "cub3d.h"

void	exit_strerror(char	*error_desc, t_core *core)
{
	free_core_map(core);
	ft_printf("%s%s", PARSING_ERROR_T, error_desc);
	exit(1);
}

void	exit_cub3d(int errcode, t_core *core)
{
	free_core(core);
	exit(errcode);
}

void	free_core_map(t_core *core)
{
	if (core)
	{
		ft_dfree((void **)core->map.buf);
		ft_va_free(5,
			core->map.filepath.north,
			core->map.filepath.south,
			core->map.filepath.east,
			core->map.filepath.west,
			core->map.buflens);
	}
}

void	free_core(t_core *core)
{
	free_core_map(core);
	mlx_terminate(core->mlx);
}
