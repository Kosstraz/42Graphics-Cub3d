/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:44:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/27 15:00:27 by mkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_core	core;

	init_core(&core);
	if (ac == 1)
		generate_map(&core);
	print_map(core);
	//if (ac == 1)					// accepter ac=1 pour la generation procedurale de map
	//	exit_strerror(CONCEDE_MAP, NULL);
	core.map.file = av[1];

	cub3d(&core);
	return (0);
}
