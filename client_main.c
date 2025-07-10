/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:23:00 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:24:23 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	int	i;

	if ((argc == 3) && (argv[1] != NULL) && (argv[2] != NULL))
	{
		i = ft_first_step(argv[1], argv[2]);
		if (i == -1)
		{
			perror("There was a mistake during process...\n");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR1, ft_signal_handler) == SIG_ERR)
		{
			perror("Error al configurar SIGUSR1");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR2, ft_signal_handler) == SIG_ERR)
		{
			perror("Error al configurar SIGUSR2");
			exit(EXIT_FAILURE);
		}
		while (1)
			pause();
	}
	else
		return (EXIT_FAILURE);
}
