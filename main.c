/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:52 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/12 15:42:25 by ymanchon         ###   ########.fr       */
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

static void	sigpipe_handling(int signum)
{
	(void)signum;
}

int	main(int ac, char **av, char **env)
{
	t_core	core;

	signal(SIGPIPE, sigpipe_handling);
	if (!env || !env[0])
		exit_strerror("No environment\n", NULL);
	if (ac < 2)
		exit_strerror("Please put a file!", NULL);
	else if (ft_strncmp_rev(av[1], ".cub", 3)
		|| (!ft_strncmp_rev(av[1], ".cub", 3)
			&& ft_strlen(av[1]) == 4))
		exit_strerror("Please put a valid .cub file\n", NULL);
	multiplayer_menu(&core);
	init_core(&core);
	if (!core.network.is_active || core.network.is_host)
		core.map.file = av[1];
	cub3d(&core);
	return (0);
}
