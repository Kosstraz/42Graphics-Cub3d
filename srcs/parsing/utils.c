/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:26:26 by ymanchon          #+#    #+#             */
/*   Updated: 2025/02/10 15:26:44 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_first_void_lines(int fd)
{
	char	*gnl;

	gnl = get_next_line(fd);
	while (gnl && gnl[0] == '\0')
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (gnl);
}

void	finish_gnl(int fd)
{
	char	*gnl;

	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
}
