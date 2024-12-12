/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:16:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/09 17:17:21 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprint(t_core *core)
{
	if (core->input_action.key_shift == TRUE)
	{
		core->player[LOCAL].bubbles_speed = BUBBLES_SPEED * 2.5f;
		core->player[LOCAL].speed = DEFPLAYERSPEED * 2.0f;
	}
	else
	{
		core->player[LOCAL].bubbles_speed = BUBBLES_SPEED;
		core->player[LOCAL].speed = DEFPLAYERSPEED;
	}
}
