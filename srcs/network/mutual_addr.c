/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutual_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:24:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/12/10 14:58:58 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_client(char *address, t_core *core)
{
	core->network.tcp.fd = socket(AF_INET, SOCK_STREAM, 0);
	inet_pton(AF_INET, address, (in_addr_t *)&core->network.tcp.sock.sin_addr.s_addr);
	core->network.tcp.sock.sin_family = AF_INET;
	core->network.tcp.sock.sin_port = htons(PORT);
	if (connect(core->network.tcp.fd, (struct sockaddr *)&core->network.tcp.sock, sizeof(struct sockaddr_in)) == -1)
	{
		close(core->network.tcp.fd);
		ft_printf("Connexion vers l'hote impossible :/\n");
		exit(1);
	}
	ft_printf("Connexion a autrui reussie.\n");
	core->network.tcp.com = dup(core->network.tcp.fd);
}

void	setup_server(t_core *core)
{
	socklen_t	socklen;
	int			uselezz;

	socklen = sizeof(struct sockaddr_in);
	uselezz = TRUE;
	core->network.tcp.fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(core->network.tcp.fd, SOL_SOCKET, SO_REUSEADDR, &uselezz, sizeof(int));
	core->network.tcp.sock.sin_family = AF_INET;
	core->network.tcp.sock.sin_port = htons(PORT);
	core->network.tcp.sock.sin_addr.s_addr = INADDR_ANY;
	if (bind(core->network.tcp.fd, (struct sockaddr *)&core->network.tcp.sock, sizeof(struct sockaddr_in)) == -1)
	{
		close(core->network.tcp.fd);
		ft_printf("Erreur lors du bind du serveur :/\n");
		//ft_printf("%d\n", errno);
		exit(1);
	}
	listen(core->network.tcp.fd, SOMAXCONN);
	ft_printf("En attente d'une connexion!\n");
	core->network.tcp.com = accept(core->network.tcp.fd, (struct sockaddr *)&core->network.tcp.sock, &socklen);
	ft_printf("Connexion entrante detectee.\n");
}

void	close_connection(t_core *core)
{
	close(core->network.tcp.fd);
	close(core->network.tcp.com);
}
