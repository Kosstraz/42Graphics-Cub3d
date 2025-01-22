/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoury <mkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:43 by ymanchon          #+#    #+#             */
/*   Updated: 2025/01/22 17:14:18 by mkhoury          ###   ########.fr       */
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
	if (scanf("%s", address) == -1)
		exit(1);
	setup_client(address, core);
}

static void	show_addresspoint(t_core *core)
{
	char			*ipv4;
	char			buffer[256];
	struct hostent	*hostaddr;
	gethostname(buffer, sizeof(buffer));
	hostaddr = gethostbyname(buffer);
	ipv4 = inet_ntoa(*(struct in_addr *)hostaddr->h_addr_list[0]);
	ft_printf("Vous pouvez-vous connecter sur l'adresse : %s:%d\n", ipv4, PORT);
	setup_server(core);
	core->network.is_host = TRUE;
}

static void	create_or_join(t_core *core)
{
	char	choice;

	ft_printf("1. CREATE SERVER\n");
	ft_printf("2. JOIN\n");
	if (scanf("%c", &choice) == -1)
		exit(1);
	while (choice != '1' && choice != '2')
	{
		ft_printf("Veuillez faire un choix valide.\n");
		if (scanf("%c", &choice) == -1)
			exit(1);
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
	if (scanf("%c", &choice) == -1)
		exit(1);
	while (choice != '1' && choice != '2')
	{
		ft_printf("Veuillez faire un choix valide.\n");
		if (scanf("%c", &choice) == -1)
			exit(1);
	}
	clear_terminal();
	if (choice == '1')
		core->network.is_active = FALSE;
	else
	{
		core->network.is_active = TRUE;
		create_or_join(core);
	}
}
