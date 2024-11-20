#include "cub3d.h"

inline static void	init_gen_config(t_gen_context *context)
{
	context->config.x.min = DEFMAPX_MIN;
	context->config.y.min = DEFMAPY_MIN;
	context->config.x.max = DEFMAPX_MAX;
	context->config.y.max = DEFMAPY_MAX;
	context->config.yfreq.min = DEFFREQ_MIN;
	context->config.yfreq.max = DEFFREQ_MIN;
	context->config.spawn1_orientation = CUB3D_PLAYER[rand_btw(0, 3)];
	context->utils.freq_index = 0;
	context->utils.freq_val = 0;
	context->utils.player_has_spawned = FALSE;
}

inline static void	config_generation(t_gen_context *context, t_core *core)
{
	core->map.generated = TRUE;
	core->map.bufmax = rand_btw(context->config.y.min, context->config.y.max);
	core->map.buf = (char **)malloc(sizeof(char *) * (core->map.bufmax + 1));
	core->map.buf[core->map.bufmax] = NULL;
	context->config.yfreq.max = (((int)(core->map.bufmax * DEFFREQ_MAX_MULTIPLIER))
			+ DEFFREQ_MAX_PRETTY_OFFSET);
	context->utils.luck_player_spawn_now = core->map.bufmax * DEFLUCK;
}

// print_configuration(context, *core);
void	generate_map(t_core *core)
{
	t_gen_context	context;

	init_gen_config(&context);
	config_generation(&context, core);
	print_configuration(context, *core);
	generate(&context, core);
}
