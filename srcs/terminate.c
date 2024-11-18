#include "cub3d.h"

void	exit_cub3d(int errcode, t_core *core)
{
	free_core(core);
	exit(errcode);
}
