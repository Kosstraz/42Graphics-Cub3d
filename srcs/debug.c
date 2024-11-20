#include "cub3d.h"

void	print_map(t_core core)
{
	size_t	i;

	i = 0;
	while (core.map.buf[i])
		ft_printf(core.map.buf[i++]);
}

void	print_color(t_color col)
{
	ft_printf("r: %d   g: %d   b: %d", col.r, col.g, col.b);
	if (col._overflow)
		ft_printf("    OVERFLOWED!");
	ft_printf("\n");
}

void	print_configuration(t_gen_context context, t_core core)
{
	ft_printf("MAP GENERATION's CONFIGURATION :\n");
	ft_printf("Y len min : %d\n", context.config.y.min);
	ft_printf("Y len max : %d\n", context.config.y.max);
	ft_printf("X len min : %d\n", context.config.x.min);
	ft_printf("X len max : %d\n", context.config.x.max);
	ft_printf("Y len choose : %d\n", core.map.bufmax);
	ft_printf("Y frequence min : %d\n", context.config.yfreq.min);
	ft_printf("Y frequence max : %d\n", context.config.yfreq.max);
	ft_printf("Player orientation : %c\n", context.config.spawn1_orientation);
	ft_printf("\n");
}
