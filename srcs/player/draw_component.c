/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:59:06 by mkhoury           #+#    #+#             */
/*   Updated: 2025/01/13 19:02:01 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_component_face(t_face face1, t_face face2, t_face face3, t_core *core)
{
	//draw_face(face1, core);
	draw_face(face2, core);
	draw_face(face3, core);
}

void	draw_component_extra(t_component component, int index, t_core *core)
{
	if (index == 4)
	{
		draw_component_face(component.face[5], component.face[2], component.face[1], core);
	}
	else if (index == 5)
	{
		draw_component_face(component.face[5], component.face[2], component.face[3], core);
	}
	else if (index == 6)
	{
		draw_component_face(component.face[5], component.face[0], component.face[3], core);
	}
	else if (index == 7)
	{
		draw_component_face(component.face[5], component.face[0], component.face[1], core);
	}
}

void	draw_component(t_component component, int index, t_core *core)
{
	if (index == 0)
	{
		draw_component_face(component.face[4], component.face[2], component.face[1], core);
	}
	else if (index == 1)
	{
		draw_component_face(component.face[4], component.face[2], component.face[3], core);
	}
	else if (index == 2)
	{
		draw_component_face(component.face[4], component.face[0], component.face[3], core);
	}
	else if (index == 3)
	{
		draw_component_face(component.face[4], component.face[0], component.face[1], core);
	}
	else
		draw_component_extra(component, index, core);
}
