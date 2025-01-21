/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:52 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/13 15:30:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_core	core;

	if (ft_strncmp_rev(av[1], ".cub", 3)
		|| (!ft_strncmp_rev(av[1], ".cub", 3)
			&& ft_strlen(av[1]) == 4))
		exit(1);
	multiplayer_menu(&core);
	init_core(&core);
	if (!core.network.is_active || core.network.is_host)
	{
		if (ac == 1)
			generate_map(&core);
		core.map.file = av[1];
	}
	cub3d(&core);
	return (0);
}
