/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:05:01 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:31:41 by ymanchon         ###   ########.fr       */
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
	Void = 0xffA4A4A4,
	Wall = 0xff585858
}	t_color_type;

#endif
