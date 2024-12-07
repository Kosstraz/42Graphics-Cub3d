/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:24:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/07 16:25:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bubbles_sin(float bubbles_min, float bubbles_max, t_core *core)
{
	if (bubbles_min != bubbles_max)
	{
		if (core->player[LOCAL].bubbles < bubbles_max && !core->player[LOCAL].maxed)
			core->player[LOCAL].bubbles += BUBBLES_SPEED * core->mlx->delta_time;
		else if (core->player[LOCAL].bubbles > bubbles_min && !core->player[LOCAL].mined)
			core->player[LOCAL].bubbles -= BUBBLES_SPEED * core->mlx->delta_time;
		if (core->player[LOCAL].bubbles >= bubbles_max)
		{
			play_sound(&core->audio[rand_btw(STEP1, STEP5)]);
			core->player[LOCAL].maxed = TRUE;
			core->player[LOCAL].mined = FALSE;
		}
		else if (core->player[LOCAL].bubbles <= bubbles_min)
		{
			core->player[LOCAL].maxed = FALSE;
			core->player[LOCAL].mined = TRUE;
		}
	}
	else if ((int)core->player[LOCAL].bubbles < (int)bubbles_max)
		core->player[LOCAL].bubbles += BUBBLES_SPEED * core->mlx->delta_time;
	else if ((int)core->player[LOCAL].bubbles > (int)bubbles_max)
		core->player[LOCAL].bubbles -= BUBBLES_SPEED * core->mlx->delta_time;
}
