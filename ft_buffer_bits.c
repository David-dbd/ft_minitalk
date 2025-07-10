/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:14:35 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:15:14 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_buffer_bits(int sig, siginfo_t *info)
{
	if (sig == SIGUSR1)
	{
		g_server.str_bits[g_server.index] = '1';
	}
	else
	{
		g_server.str_bits[g_server.index] = '0';
	}
	g_server.index++;
	if (g_server.index == 8)
		ft_client_str(info);
	if (g_server.stop == 0)
		kill(info->si_pid, SIGUSR1);
	return (0);
}
