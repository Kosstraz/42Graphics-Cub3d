/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:54:09 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/04 20:49:17 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void my_audio_callback(void* userdata, Uint8* stream, int len)
{
	t_audio_data*	audio;
	
	audio = (t_audio_data*)userdata;
	if (audio->audio_len == 0)
		return;

	len = ((Uint32)len > audio->audio_len) ? audio->audio_len : len;
	SDL_memcpy(stream, audio->audio_pos, len);
	audio->audio_pos += len;
	audio->audio_len -= len;
}

void	init_audiosys(t_core *core)
{
	(void)core;
	SDL_AudioSpec	*wav_spec;
	Uint8*			wav_buffer;
	Uint32			wav_length;

	wav_spec = malloc(sizeof(SDL_AudioSpec));
	SDL_Init(SDL_INIT_AUDIO);
	if (SDL_LoadWAV("Assets/audio/MainTheme.wav", wav_spec, &wav_buffer, &wav_length) == NULL)
	{
		fprintf(stderr, "Erreur lors du chargement du fichier WAV: %s\n", SDL_GetError());
		SDL_Quit();
	}

	t_audio_data	audio_data;
	audio_data.audio_pos = wav_buffer;
	audio_data.audio_len = wav_length;
	wav_spec->callback = my_audio_callback;
	wav_spec->userdata = &audio_data;

    // Ouvrir le périphérique audio
    SDL_AudioDeviceID device_id = SDL_OpenAudioDevice(NULL, 0, wav_spec, NULL, 0);
    if (device_id == 0)
	{
        fprintf(stderr, "Erreur lors de l'ouverture du périphérique audio: %s\n", SDL_GetError());
        SDL_FreeWAV(wav_buffer);
        SDL_Quit();
    }

    // Démarrer la lecture audio
    SDL_PauseAudioDevice(device_id, 0);

    // Attendre que l'audio soit terminé
    //while (audio_data.audio_len > 0)
	//{
    //    SDL_Delay(100); // Attendre 100 ms
    //}
//
    //// Nettoyer et quitter
    //SDL_CloseAudioDevice(device_id);
    //SDL_FreeWAV(wav_buffer);
    //SDL_Quit();
}
