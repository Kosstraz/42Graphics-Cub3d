/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:37:07 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/28 17:00:47 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	init_player(t_player *player)
{
	ft_memset(player, 0, sizeof(t_player));
	player->life = MAX_LIFE;
}

inline static void	init_core_map(t_core *core)
{
	core->map.generated = FALSE;
	core->map.bufmax = DEFMAPBUF;
	core->map.buf = (char **)malloc(sizeof(char *) * DEFMAPBUF);
	core->map.buflens = NULL;
	core->map.buflens_size = 0;
	ft_memset(&core->map.filepath, 0, sizeof(t_filepath));
	ft_memset(core->map.cf_colors, 0, sizeof(t_color) * 2);
	//core->map.cf_colors[C] = ctocol(0, 0, 0);
	//core->map.cf_colors[F] = ctocol(0, 0, 0);
	//core->map.cf_colors[C]._overflow = FALSE;
	//core->map.cf_colors[F]._overflow = FALSE;
}

inline void	init_core(t_core *core)
{
	int	i;

	i = 0;
	core->mouse_visible = FALSE;
	core->mlx.half_height = DEFHEIGHT / 2.f;
	core->mlx.half_width = DEFWIDTH / 2.f;
	core->layer[MINIMAP_LAYER].pixels = NULL;
	core->layer[CAST_LAYER].pixels = NULL;
	core->fps_cooldown = 0;
	core->delta_time = 0.0f;
	ft_memset(&core->imgs, 0, sizeof(t_img_container));
	ft_memset(&core->minimap, 0, sizeof(t_minimap));
	ft_memset(&core->input_action, 0, sizeof(t_input_action));
	init_player(&core->player[LOCAL]);
	init_player(&core->player[DISTANT]);
	init_core_map(core);
	init_cast(&core->cast, core->player[LOCAL]);
}

inline void	init_mlx_env(t_core *core)
{
	cub_mlx_init(core);
	core->minimap.size.x = core->map.buflens_max * DEFUNIT;
	core->minimap.size.y = core->map.bufmax * DEFUNIT;
	cub_new_image(&core->imgs.minimap, core->minimap.size.x, core->minimap.size.y, core);
	cub_new_image(&core->imgs.cast, core->mlx.width, core->mlx.height, core);
	init_layer(&core->imgs.minimap, &core->layer[MINIMAP_LAYER]);
	init_layer(&core->imgs.cast, &core->layer[CAST_LAYER]);
	//printf("%i %i init\n", core->mlx->width, core->mlx->height);
}

inline void	setup_mlx_hooks(t_core *core)
{
	mlx_mouse_hook(core->mlx.context, (t_mlx_mousefunc)cub3d_mouse_hook, core);
	mlx_key_hook(core->mlx.context, (t_mlx_keyfunc)cub3d_key_hook, core);
	mlx_loop_hook(core->mlx.context, (t_mlx_loopfunc)game, core);
}
