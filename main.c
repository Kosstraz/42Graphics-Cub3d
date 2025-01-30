/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:52 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/27 18:52:46 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_uint	rand_btw(t_uint min, t_uint max)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	return ((rand() % (max - min + 1)) + min);
}

int	main(int ac, char **av)
{
	t_core	core;

	if (ac < 2)
		exit_strerror("Please put a file!", NULL);
	else if (ft_strncmp_rev(av[1], ".cub", 3)
		|| (!ft_strncmp_rev(av[1], ".cub", 3)
			&& ft_strlen(av[1]) == 4))
		exit(1);
	multiplayer_menu(&core);
	init_core(&core);
	if (!core.network.is_active || core.network.is_host)
		core.map.file = av[1];
	cub3d(&core);
	return (0);
}
