/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:43 by ymanchon          #+#    #+#             */
/*   Updated: 2024/11/25 19:10:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_terminal(void)
{
	char	i;

	i = 0;
	while (i++ < 25)
		ft_printf("\n");
}

static void	demande_addresspoint(t_core *core)
{
	char	address[INET_ADDRSTRLEN];

	ft_printf("Adresse : ");
	scanf("%s", address);
	setup_client(address, core);
}

static void	show_addresspoint(t_core *core)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*ip;
	char				*port;
	char				ip_str[INET_ADDRSTRLEN];

	ft_memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	port = ft_itoa(PORT);
	if (getaddrinfo(NULL, port, &hints, &res) != 0)
	{
		ft_printf("Erreur lors de l'essaie de la recuperation de l'adresse IPv4.\n");
		free(port);
		exit(0);
	}
	free(port);
	ip = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(AF_INET, &ip->sin_addr, ip_str, sizeof(ip_str));
	freeaddrinfo(res);
	ft_printf("Vous pouvez-vous connecter sur l'adresse : %s:%d\n", ip_str, PORT);
	setup_server(core);
	core->multi.is_host = TRUE;
}

static void	create_or_join(t_core *core)
{
	char	choice;

	ft_printf("1. CREATE SERVER\n");
	ft_printf("2. JOIN\n");
	scanf("\n%c", &choice);
	while (choice != '1' && choice != '2')
	{
		ft_printf("Veuillez faire un choix valide.\n");
		scanf("%c", &choice);
	}
	clear_terminal();
	if (choice == '1')
		show_addresspoint(core);
	else if (choice == '2')
		demande_addresspoint(core);
}

void	multiplayer_menu(t_core *core)
{
	char	choice;

	init_network(core);
	ft_printf("1. SOLO\n");
	ft_printf("2. MULTI\n");
	scanf("%c", &choice);
	while (choice != '1' && choice != '2')
	{
		ft_printf("Veuillez faire un choix valide.\n");
		scanf("%c", &choice);
	}
	clear_terminal();
	if (choice == '1')
		core->multi.is_active = FALSE;
	else
	{
		core->multi.is_active = TRUE;
		create_or_join(core);
	}
}
