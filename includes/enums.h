/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:05:01 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/21 14:10:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_color_type
{
	Transparent = 0x00000000,
	White = 0xffffffff,
	Black = 0x000000ff,
	Red = 0xff0000ff,
	Green = 0x00ff00ff,
	Blue = 0x0000ffff,
	Player = 0xB40404ff,
	Void = 0xA4A4A4ff,
	Wall = 0x585858ff
}	t_color_type;

#endif
