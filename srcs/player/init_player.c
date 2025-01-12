/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:48:27 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/12 17:10:06 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_player_entity(t_player *player)
{
    player->view.angle = 0.f;
    set_corps(player);
    set_head(player);
	set_arms(player);
	set_legs(player);
}
