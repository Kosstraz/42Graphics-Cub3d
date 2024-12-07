/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:05:01 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/06 18:50:20 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_color_type
{
	Transparent = 0x00000000,
	White = 0xffffffff,
	Black = 0xff000000,
	Red = 0xff0000ff,
	Green = 0xff00ff00,
	Blue = 0xffff0000,
	Player = 0xff0404B4,
	Void = 0xff949494,
	Door = 0xff909065,
	Wall = 0xff4A4A4A
}	t_color_type;

typedef t_color_type	t_col_t;

typedef enum e_entity_type
{
	joueur = 0,
	Enemy = 1,
	Item = 1
}	t_entity_type;

#endif
