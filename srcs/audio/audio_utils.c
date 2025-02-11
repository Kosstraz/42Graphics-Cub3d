/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:33 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/11 16:38:58 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sdl_mixaudioformat(
	Uint8 *dst,
	const Uint8 *src,
	SDL_AudioFormat format,
	t_posi len_and_index)
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

void	destroy_audio_system(t_core *core)
{
	int	i;

	i = 0;
	SDL_CloseAudio();
	while (i < NB_SOUNDS)
	{
		if (core->audio[i].buffer)
			SDL_FreeWAV(core->audio[i].buffer);
		++i;
	}
	SDL_Quit();
	free(core->spec);
}

void	play_sound(t_audio *audio)
{
	if (ACTIVE_AUDIO)
	{
		if (audio->buffer == NULL)
			return ;
		audio->pos = audio->buffer;
		audio->len = audio->start_len;
		audio->is_active = TRUE;
	}
}
