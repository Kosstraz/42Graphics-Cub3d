/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:53:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/26 20:51:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_client_udp(t_core *core)
{
	char	test_addr;

	test_addr = 42;
	core->network.udp.com.sin_family = AF_INET;
	core->network.udp.com.sin_port = htons(PORT);
	if (inet_pton(AF_INET, core->network.hostaddr, &core->network.udp.com.sin_addr.s_addr) == -1)
	{
		ft_printf("Invalid address :/\n");
		exit(1);
	}
	core->network.udp.fd = socket(AF_INET, SOCK_DGRAM, 0);
	core->network.udp.len = sizeof(struct sockaddr_in);
	setsockopt(core->network.udp.fd, SOL_SOCKET, SO_REUSEADDR, &test_addr, sizeof(int));
	//int flags = fcntl(core->network.udp.fd, F_GETFL, 0);
	//fcntl(core->network.udp.fd, F_SETFL, flags | O_NONBLOCK);
	udp_send(&test_addr, sizeof(char), core, POLL_SYNC_TO_SERVER);
	//if (sendto(core->network.udp.fd, &test_addr, sizeof(int), 0, (struct sockaddr *)&core->network.udp.com, core->network.udp.len) == -1)
}

void	setup_server_udp(t_core *core)
{
	int	test_addr;

	test_addr = TRUE;
	core->network.is_host = TRUE;
	core->network.udp.com.sin_family = AF_INET;
	core->network.udp.com.sin_port = htons(PORT);
	core->network.udp.com.sin_addr.s_addr = INADDR_ANY;
	core->network.udp.fd = socket(AF_INET, SOCK_DGRAM, 0);
	core->network.udp.len = sizeof(struct sockaddr_in);
	setsockopt(core->network.udp.fd, SOL_SOCKET, SO_REUSEADDR, &test_addr, sizeof(int));
	if (bind(core->network.udp.fd, (struct sockaddr *)&core->network.udp.com, core->network.udp.len) == -1)
	{
		ft_printf("Erreur lors du bind du host !\n");
		exit(1);
	}
	ft_printf("En attente d'une tentative de connexion...\n");
	udp_recvs(core);
	//recvfrom(core->network.udp.fd, &test_addr, sizeof(int), 0, (struct sockaddr *)&core->network.udp.com, &core->network.udp.len);
	ft_printf("Connexion effectuee\n");
}

void	setup_client_tcp(char *address, t_core *core)
{
	core->network.tcp.fd = socket(AF_INET, SOCK_STREAM, 0);
	inet_pton(AF_INET, address, (in_addr_t *)&core->network.tcp.sock.sin_addr.s_addr);
	core->network.hostaddr = address;
	core->network.tcp.sock.sin_family = AF_INET;
	core->network.tcp.sock.sin_port = htons(PORT);
	if (connect(core->network.tcp.fd, (struct sockaddr *)&core->network.tcp.sock, sizeof(struct sockaddr_in)) == -1)
	{
		close(core->network.tcp.fd);
		ft_printf("Connexion vers l'hote impossible :/\n");
		exit(1);
	}
	ft_printf("Connexion a autrui reussie.\n");
	core->network.tcp.com = dup(core->network.tcp.fd); //! enlever dup() si pb
}

void	setup_server_tcp(t_core *core)
{
	socklen_t	socklen;
	int			opt;
	int			flags;

	socklen = sizeof(struct sockaddr_in);
	opt = TRUE;
	core->network.tcp.fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(core->network.tcp.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
	core->network.tcp.sock.sin_family = AF_INET;
	core->network.tcp.sock.sin_port = htons(PORT);
	core->network.tcp.sock.sin_addr.s_addr = INADDR_ANY;
	if (bind(core->network.tcp.fd, (struct sockaddr *)&core->network.tcp.sock, sizeof(struct sockaddr_in)) == -1)
	{
		close(core->network.tcp.fd);
		ft_printf("Erreur lors du bind du serveur :/\n");
		exit(1);
	}
	listen(core->network.tcp.fd, SOMAXCONN);
	ft_printf("En attente d'une connexion!\n");
	core->network.tcp.com = accept(core->network.tcp.fd, (struct sockaddr *)&core->network.tcp.sock, &socklen);
	ft_printf("Connexion entrante detectee.\n");
}
