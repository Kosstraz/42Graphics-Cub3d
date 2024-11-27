/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:05:01 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 13:50:42 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_color_type
{
	Transparent = 0x00000000,
	White = 0xffffffff,
	Black = 0x000000ff,
	Red = 0xff0000ff,//0xff0000ff,
	Green = 0xff00ff00,//0x00ff00ff,
	Blue = 0xffff0000,//0x0000ffff,
	Player = 0xff0404B4,//0xB40404ff,
	Void = 0xffA4A4A4,//0xA4A4A4ff,
	Wall = 0xff585858//0x585858ff
}	t_color_type;

#endif
