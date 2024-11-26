/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutual_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:24:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 15:53:02 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_client(char *address, t_core *core)
{
	core->multi.network.fd = socket(AF_INET, SOCK_STREAM, 0);
	inet_pton(AF_INET, address, (struct sockaddr *)&core->multi.network.sock);
	core->multi.network.sock.sin_family = AF_INET;
	core->multi.network.sock.sin_port = htons(PORT);
	if (connect(core->multi.network.fd, (struct sockaddr *)&core->multi.network.sock, sizeof(struct sockaddr_in)) == -1)
	{
		close(core->multi.network.fd);
		ft_printf("Connexion vers l'hote impossible :/\n");
		exit(1);
	}
	ft_printf("Connexion a autrui reussie.\n");
	core->multi.network.com = dup(core->multi.network.fd); //! enlever dup() si pb
}

void	setup_server(t_core *core)
{
	socklen_t	socklen;
	int		uselezz;
	int			flags;

	socklen = sizeof(struct sockaddr_in);
	uselezz = TRUE;
	core->multi.network.fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(core->multi.network.fd, SOL_SOCKET, SO_REUSEADDR, &uselezz, sizeof(int));
	core->multi.network.sock.sin_family = AF_INET;
	core->multi.network.sock.sin_port = htons(PORT);
	core->multi.network.sock.sin_addr.s_addr = INADDR_ANY;
	if (bind(core->multi.network.fd, (struct sockaddr *)&core->multi.network.sock, sizeof(struct sockaddr_in)) == -1)
	{
		close(core->multi.network.fd);
		ft_printf("Erreur lors du bind du serveur :/\n");
		//ft_printf("%d\n", errno);
		exit(1);
	}
	listen(core->multi.network.fd, SOMAXCONN);
	ft_printf("En attente d'une connexion!\n");
	core->multi.network.com = accept(core->multi.network.fd, (struct sockaddr *)&core->multi.network.sock, &socklen);
	ft_printf("Connexion entrante detectee.\n");
	//flags = fcntl(core->multi.network.fd, F_GETFL, 0);
	//fcntl(core->multi.network.fd, F_SETFL, flags | O_NONBLOCK);
}

void	close_connection(t_core *core)
{
	close(core->multi.network.fd);
	close(core->multi.network.com);
}
