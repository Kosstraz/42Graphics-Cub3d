/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:54:09 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/30 14:26:55 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_posi	set_posi(int x, int y)
{
	t_posi	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	audio_player(
	void *userdata,
	uint8_t *stream,
	int len)
{
	t_core_audio	ca;

	ca.i = -1;
	ca.core = (t_core *)userdata;
	SDL_memset(stream, 0, len);
	while (++ca.i < NB_SOUNDS)
	{
		ca.audio = &ca.core->audio[ca.i];
		if (ca.audio->is_active && ca.audio->len > 0)
		{
			ca.to_copy = len;
			if (len > (int)ca.audio->len)
				ca.to_copy = ca.audio->len;
			ca.len_index = set_posi(ca.to_copy, ca.i);
			ft_sdl_mixaudioformat(
				stream,
				ca.audio->pos,
				ca.core->spec->format,
				ca.len_index);
			ca.audio->pos += ca.to_copy;
			ca.audio->len -= ca.to_copy;
			if (ca.audio->len == 0)
				ca.audio->is_active = FALSE;
		}
	}
}

static void	load_wavfile(
	const char *filename,
	t_audio *audio,
	SDL_AudioSpec *spec)
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
	load_wavfile("./Assets/sounds/Ambient2.wav", &core->audio[AMBIENT],
		core->spec);
	load_wavfile("./Assets/sounds/GoofyRunningSoundEffect.wav",
		&core->audio[PRANK], core->spec);
	load_wavfile("./Assets/sounds/FreakySoundEffects.wav", &core->audio[FREAKY],
		core->spec);
	load_wavfile("./Assets/sounds/step1.wav", &core->audio[STEP1], core->spec);
	load_wavfile("./Assets/sounds/step2.wav", &core->audio[STEP2], core->spec);
	load_wavfile("./Assets/sounds/step3.wav", &core->audio[STEP3], core->spec);
	load_wavfile("./Assets/sounds/step4.wav", &core->audio[STEP4], core->spec);
	load_wavfile("./Assets/sounds/step5.wav", &core->audio[STEP5], core->spec);
	load_wavfile("./Assets/sounds/door1.wav", &core->audio[DOOR1], core->spec);
	load_wavfile("./Assets/sounds/door2.wav", &core->audio[DOOR2], core->spec);
	load_wavfile("./Assets/sounds/door3.wav", &core->audio[DOOR3], core->spec);
	load_wavfile("./Assets/sounds/TorchOn.wav", &core->audio[TORCHON],
		core->spec);
	load_wavfile("./Assets/sounds/TorchOff.wav", &core->audio[TORCHOFF],
		core->spec);
	init_audio_spec(core, core->spec);
	if (SDL_OpenAudio(core->spec, NULL))
		ft_printf("Failed to open SDL audio\n");
	SDL_PauseAudio(0);
}
