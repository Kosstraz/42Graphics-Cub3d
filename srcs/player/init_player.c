/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:48:27 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/13 17:17:00 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_player_entity(t_player *player, t_core *core)
{
    player->view.angle = 0.f;
    set_corps(player, core);
    set_head(player, core);
	set_arms(player, core);
	set_legs(player, core);
}
