/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:56:11 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:01:16 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_client	g_server;

void	handler(int sig, siginfo_t *info, void *context __attribute__((unused)))
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		usleep(50);
		if (g_server.pid == -1)
		{
			g_server.pid = info->si_pid;
			g_server.stop = 0;
		}
		else if (g_server.pid != info->si_pid)
		{
			ft_init_clients();
			g_server.pid = -1;
			g_server.stop = 0;
		}
		ft_buffer_bits(sig, info);
		return ;
	}
	else
		return ;
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Error al configurar SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error al configurar SIGUSR2");
		exit(EXIT_FAILURE);
	}
	ft_init_clients();
	g_server.pid = -1;
	ft_printf("%d \n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
