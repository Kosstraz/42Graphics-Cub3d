/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:54:09 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/09 13:14:49 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	audio_player(void *userdata, uint8_t *stream, int len)
{
	t_core	*core;
	t_audio	*audio;
	size_t		i;
	int			to_copy;
	t_posi		len_index;

	i = 0U;
	core = (t_core *)userdata;
	SDL_memset(stream, 0, len);
	while (i < NB_SOUNDS)
	{
		audio = &core->audio[i];
		if (audio->is_active && audio->len > 0)
		{
			if (len > (int)audio->len)
				to_copy = audio->len;
			else
				to_copy = len;
			len_index.x = to_copy;
			len_index.y = i;
			ft_SDL_MixAudioFormat(stream, audio->pos, core->spec->format, len_index);
			audio->pos += to_copy;
			audio->len -= to_copy;
			if (audio->len == 0)
				audio->is_active = FALSE;
		}
		++i;
	}
}

static void	load_wavfile(const char *filename, t_audio *audio, SDL_AudioSpec *spec)
{
	if (SDL_LoadWAV(filename, spec, &audio->buffer, &audio->len) < 0)
		ft_printf("Failed to load %s (%s)\n", filename, SDL_GetError());
	audio->pos = audio->buffer;
	audio->start_len = audio->len;
	audio->is_active = FALSE;
}

void	init_audio_spec(t_core *core, SDL_AudioSpec *spec)
{
	spec->freq = 44100;
    spec->format = AUDIO_S16LSB;
    spec->channels = 2;
    spec->samples = 4096;
	spec->callback = audio_player;
	spec->userdata = core;
}

void	init_audio_system(t_core *core)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		ft_printf("Failed to init SDL AUDIO\n");
	core->spec = (SDL_AudioSpec *)malloc(sizeof(SDL_AudioSpec));
	load_wavfile("./Assets/sounds/Ambient2.wav", &core->audio[AMBIENT], core->spec);
	load_wavfile("./Assets/sounds/GoofyRunningSoundEffect.wav", &core->audio[PRANK], core->spec);
	load_wavfile("./Assets/sounds/FreakySoundEffects.wav", &core->audio[FREAKY], core->spec);
	load_wavfile("./Assets/sounds/step1.wav", &core->audio[STEP1], core->spec);
	load_wavfile("./Assets/sounds/step2.wav", &core->audio[STEP2], core->spec);
	load_wavfile("./Assets/sounds/step3.wav", &core->audio[STEP3], core->spec);
	load_wavfile("./Assets/sounds/step4.wav", &core->audio[STEP4], core->spec);
	load_wavfile("./Assets/sounds/step5.wav", &core->audio[STEP5], core->spec);
	load_wavfile("./Assets/sounds/door1.wav", &core->audio[DOOR1], core->spec);
	load_wavfile("./Assets/sounds/door2.wav", &core->audio[DOOR2], core->spec);
	load_wavfile("./Assets/sounds/door3.wav", &core->audio[DOOR3], core->spec);
	load_wavfile("./Assets/sounds/TorchOn.wav", &core->audio[TORCHON], core->spec);
	load_wavfile("./Assets/sounds/TorchOff.wav", &core->audio[TORCHOFF], core->spec);
	init_audio_spec(core, core->spec);
	if (SDL_OpenAudio(core->spec, NULL))
		ft_printf("Failed to open SDL audio\n");
	SDL_PauseAudio(0);
}

void	play_sound(t_audio *audio)
{
	if (audio->buffer == NULL)
		return ;
	audio->pos = audio->buffer;
	audio->len = audio->start_len;
	audio->is_active = TRUE;
}

void	destroy_audio_system(t_core *core)
{
	SDL_CloseAudio();
	if (core->audio[AMBIENT].buffer)
		SDL_FreeWAV(core->audio[AMBIENT].buffer);
	if (core->audio[PRANK].buffer)
		SDL_FreeWAV(core->audio[PRANK].buffer);
	SDL_Quit();
}
