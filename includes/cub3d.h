/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:48 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/13 17:25:56 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <poll.h>

# include <SDL2/SDL.h>
# include <SDL2/SDL_audio.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>
# include "MLX42-2.4.1/include/MLX42/MLX42.h"
# include "libft.h"
# include "platform.h"
# include "defs.h"
# include "enums.h"

	/*
		CORE
	*/

long	torch(int x, int y, float length, long basecolor, t_core *core);
void	bubbles_sin(float bubbles_min, float bubbles_max, t_core *core);
void	door_raycast(t_core *core);
void	init_audio_system(t_core *core);
void	play_sound(t_audio *audio);
void	destroy_audio_system(t_core *core);
void	player_check_movements(t_core *core);
void	player_check_orientationraycast(t_core *core);
void	handle_doors_key(mlx_key_data_t keyd, t_core *core);
int		doors_check_state(int x, int y, t_core *core);
float	vector_norm(float x, float y);
t_uint	coltoui(t_color c);
void	sprint(t_core *core);

	//* main files (cub3d.c)
void	cub3d(t_core *core);
void	game(t_core *core);

	//* init.c
void	init_core(t_core *core);
void	init_mlx_env(t_core *core);
void	setup_mlx_hooks(t_core *core);

	//* terminate.c
void	exit_strerror(char	*error_desc, t_core *core);
void	exit_cub3d(int errcode, t_core *core);
void	free_core(t_core *core);
void	free_core_map(t_core *core);

	//* key_handing
void	handle_pressing_alt_key(mlx_key_data_t keyd, t_core *core);
void	handle_releasing_alt_key(mlx_key_data_t keyd, t_core *core);
void	handle_esc_key(mlx_key_data_t keyd, t_core *core);
void	handle_player_key_press(mlx_key_data_t keyd, t_core *core);
void	handle_player_key_release(mlx_key_data_t keyd, t_core *core);
void	handle_crouchplayer_key(mlx_key_data_t keyd, t_core *core);

	//* utils_colors
t_color	ctocol(t_uchar r, t_uchar g, t_uchar b);
t_uint	coltohexa(t_color col);
t_color	stocol(const char *str);

	//* debug.c
void	print_color(t_color col);
void	print_configuration(t_gen_context context, t_core core);
void	print_map(t_core core);

	//* hooks.c
void	cub3d_close_hook(t_core *core);
void	cub3d_key_hook(mlx_key_data_t keyd, t_core *core);
void	cub3d_cursor_hook(double xpos, double ypos, t_core *core);
void	cub3d_scroll_hook(double xdelta, double ydelta, t_core *core);
void	cub3d_resize_hook(int width, int height, t_core *core);
void	cub3d_mouse_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, t_core *core);

	/*
		PARSING
	*/

	//* parsing/parsing_asciimap.c
void	parse_asciimap(int fd, t_core *core);

	//* parsing/parsing_check_errors.c
void	parse_texturefile_path_error(t_core *core);
void	parse_cf_colors_error(BOOL cf[2], t_core *core);

	//* parsing/parsing.c
void	parse_map(t_core *core);

	//* pc/procedural_creation.c
void	generate_map(t_core *core);

	//* pc/utils.c
t_uint	rand_btw(t_uint min, t_uint max);

	//* pc/algo.c
void	generate(t_gen_context *context, t_core *core);

	//* pc/algo_delegate.c
char	put_outline_walls(size_t x, size_t y, t_core *core);
void	fill_line(t_gen_context *context, size_t x, size_t y, t_core *core);
void	try_shift_line(t_gen_context *context, size_t y, t_core *core);
void	try_spawn_player(
			t_gen_context *context,
			size_t y,
			size_t x,
			t_core *core);

void	init_layer(mlx_image_t *img, t_layer *layer);
void	fill_layer(t_layer *layer, t_col_t color);
void	free_layer(t_layer *layer);
void	send_textures(t_core *core);
void	recv_textures(t_core *core);
void	ft_SDL_MixAudioFormat(Uint8 *dst, const Uint8 *src, SDL_AudioFormat format, t_posi len_and_index);

	/*
		RENDERING
	*/

t_col_t	increase_lighting(t_color_type col, int by);
void	show_fps(t_core *core);
void	mlx_put_line(t_layer *layer, t_pos a, t_pos b, t_color_type color);
void	draw_minimap(t_core *core);
void	draw_square(t_layer *layer, t_pos a, t_color_type color);
char	cmppixel(
			uint32_t x,
			uint32_t y,
			t_color_type color,
			t_layer *layer);
int	draw_pixel(
			uint32_t x,
			uint32_t y,
			t_color_type color,
			t_layer *layer)	__attribute__((hot));
void	orientation_minimap(t_core *core);
float	ray_cast(t_core *core, float angle, int i);
void	init_cast(t_casting *cast, t_player player);
void	calcul_casts(t_core *core);
void	draw_cast(t_core *core);
float	deg2rad(float deg);

	/*
		MULTIJOUEUR
	*/

void	multiplayer_menu(t_core *core);
void	setup_server(t_core *core);
void	setup_client(char *address, t_core *core);
void	close_connection(t_core *core);
void	send_map(t_core *core);
void	recv_map(t_core *core);
void	init_network(t_core *core);
void	send_element(void *what, size_t size, char poll_id, t_core *core);
void	recv_any_element(t_core *core);

long int	get_time2(void);
void		clear_img(t_core *core);
void	draw_col(int x, const float y1, float length, t_core *core);
void	draw_rectangle(long distance, int x, t_core *core);
//void	draw_joueur(t_core *core);
float	rad2deg(float rad);
float	modulo_float(float nb, float mod);
float	get_angle(float dx, float dy);
void	draw_rectangle2(int x, int y, long color, t_core *core);

void    init_face(t_face *face, t_pos *points[4], int pos[2], mlx_texture_t *texture);
void    set_point(t_pos *point, float att[3], t_pos pos);
void    init_player_entity(t_player *player, t_core *core);
void	sort_distance(int *tbl[6][3]);
void	draw_face(t_face face, t_core *core);
void	draw_face_extra(t_screenp points[4], t_face face, t_core *core);
void	draw_component(t_component component, int index, t_core *core);
void	draw_line_texture(t_screenp points[2], t_face face, t_core *core, float prc);
void	draw_t1(t_screenp points[3], t_core *core, t_face face);
void    draw_player_2(t_core *core, t_player *distant, t_player *local);
void    set_arms(t_player *player, t_core *core);
void    set_legs(t_player *player, t_core *core);
void    set_head(t_player *player, t_core *core);
void    set_corps(t_player *player, t_core *core);
void	send_entity_points(t_core *core);
void	recv_entity_points(t_core *core);
void	change_ptr(t_core *core, t_player *player);




t_color_type	decrease_lighting(t_color_type col, int by);


#endif
