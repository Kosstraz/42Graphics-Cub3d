/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:16:09 by mkhoury           #+#    #+#             */
/*   Updated: 2024/12/05 14:24:00 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	joueur_visible(t_core *core, float angle_joueurs)
{
	float	angle_1;
	float	angle_2;
	float	perso_angle;

	perso_angle = core->player->view.angle;
	angle_1 = perso_angle + core->cast.hfov;
	angle_2 = perso_angle - core->cast.hfov;
	if (angle_1 > 360)
		angle_1 = modulo_float(angle_1, 360.f);
	if (angle_2 < 0)
		angle_2 = 360 + angle_2;
	//printf("angle 1 %f angle 2 %f angle js %f angle j %f\n", angle_1, angle_2, angle_joueurs, perso_angle);
	if (angle_1 < angle_2 && ((angle_joueurs <= angle_1 && angle_joueurs >= 0) || (angle_joueurs >= angle_2 && angle_joueurs <= 360)))
		return (true);
	if (angle_joueurs <= angle_1 && angle_joueurs >= angle_2)
		return (true);
	//printf("error angle 1 %f angle 2 %f angle js %f angle j %f\n", angle_1, angle_2, angle_joueurs, perso_angle);
	return (false);
}

// void	set_point(t_pos *points, t_pos player)
// {
// 	points[0].x = player.x + HITBOX;
// 	points[0].y = player.y + HITBOX;
// 	points[0].z = player.z;
	
// 	points[1].x = player.x - HITBOX;
// 	points[1].y = player.y + HITBOX;
// 	points[1].z = player.z;

// 	points[2].x = player.x - HITBOX;
// 	points[2].y = player.y - HITBOX;
// 	points[2].z = player.z;

// 	points[3].x = player.x + HITBOX;
// 	points[3].y = player.y - HITBOX;
// 	points[3].z = player.z;
// }

float	get_distance(t_pos player1, t_pos player2)
{
	return ( sqrtf((player1.x - player2.x) * (player1.x - player2.x) + (player1.y - player2.y) * (player1.y - player2.y)));
}

int	get_x(int angle_j, float *angles, int lim)
{
	int	i;

	i = 0;
	while (i < lim)
	{
		// printf("agnle joueurs %i angle sav %i",angle_j, (int) roundf(angles[i]));
		if (angle_j == (int) roundf(angles[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	draw_joueur(t_core *core)
{
	float	angle_joueurs;
	float	players_distance;
	t_pos	points[4];
	int		x;
	
	float	deltay = core->player[DISTANT].position.y - core->player[LOCAL].position.y;
	float	deltax = core->player[DISTANT].position.x - core->player[LOCAL].position.x;
	//printf("delta x %f delta y %f\n",deltax , deltay);
	
	angle_joueurs = get_angle(deltax, deltay);
	//printf("angle is %f\n", angle_joueurs);
	if (joueur_visible(core, angle_joueurs) == false)
		return ;
	players_distance = get_distance(core->player[LOCAL].position, core->player[DISTANT].position);
	//printf("angle avec l'autre j %i et la distance %f\n", angle_joueurs, players_distance);
	x = get_x(angle_joueurs, core->cast.angle, core->imgs.cast->width);
	if (x == -1)
		return ;
	//printf("wall %f player %f\n", core->cast.casts[x], players_distance);
	if (core->cast.casts[x] < players_distance )
		return ;
	//set_point(&points, core->player[DISTANT].position);
	draw_rectangle(players_distance, x, core);
}
