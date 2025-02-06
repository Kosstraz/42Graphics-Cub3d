/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asciimap2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:40:20 by bama              #+#    #+#             */
/*   Updated: 2025/02/05 14:49:24 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_asciilines2_else(
	const char *line,
	bool players_spawn[2],
	int i_cur[2],
	t_core *core)
{
	if (!players_spawn[LOCAL] && ft_isanychr(line[i_cur[0]], CUB3D_PLAYER))
	{
		core->player[LOCAL].position.x = i_cur[0];
		core->player[LOCAL].position.y = i_cur[1];
		players_spawn[LOCAL] = TRUE;
	}
	else if (core->network.is_active && !players_spawn[DISTANT]
		&& players_spawn[LOCAL] && ft_isanychr(line[i_cur[0]], CUB3D_PLAYER))
	{
		core->player[DISTANT].position.x = i_cur[0];
		core->player[DISTANT].position.y = i_cur[1];
		players_spawn[DISTANT] = TRUE;
	}
	else if ((!core->network.is_active || players_spawn[DISTANT])
		&& players_spawn[LOCAL] && ft_isanychr(line[i_cur[0]], CUB3D_PLAYER))
		exit_strerror(MAP_PLAYER_REDIFINED_T, core);
	else if (!ft_isanychr(line[i_cur[0]], CUB3D_ALL))
		exit_strerror(MAP_INVALID_CHARACTER_T, core);
}

// i_cur[0] --> i
// i_cur[1] --> cur
void	parse_asciilines2(
	const char *line,
	bool players_spawn[2],
	int i_cur[2],
	t_core *core)
{
	if (line[i_cur[0]] == CUB3D_DOOR)
	{
		core->map.doors = (t_door *)ft_realloc(core->map.doors,
				core->map.nb_of_doors
				* sizeof(t_door), (core->map.nb_of_doors + 1U) * sizeof(t_door));
		ft_memset(&core->map.doors[core->map.nb_of_doors], 0, sizeof(t_door));
		core->map.doors[core->map.nb_of_doors].pos.x = i_cur[0];
		core->map.doors[core->map.nb_of_doors].pos.y = i_cur[1];
		core->map.doors[core->map.nb_of_doors++].is_open = FALSE;
	}
	else
		parse_asciilines2_else(line, players_spawn, i_cur, core);
}
