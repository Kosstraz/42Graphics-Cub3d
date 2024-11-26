/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 19:15:47 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_core	core;

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
