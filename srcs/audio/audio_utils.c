/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:33 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/09 13:15:06 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_SDL_MixAudioFormat(Uint8 *dst, const Uint8 *src, SDL_AudioFormat format, t_posi len_and_index)
{
	if (len_and_index.y == AMBIENT)
		SDL_MixAudioFormat(
			dst,
			src,
			format,
			len_and_index.x,
			64
		);
	else
		SDL_MixAudioFormat(
			dst,
			src,
			format,
			len_and_index.x,
			SDL_MIX_MAXVOLUME
		);
}
