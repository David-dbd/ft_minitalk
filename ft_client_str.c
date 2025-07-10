/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:15:31 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:17:15 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	ft_convertion(char *buffer, int distance)
{
	int	i;
	int	result;
	int	power;

	i = 0;
	result = 0;
	while (i < distance && buffer[i] != '\0')
	{
		power = distance - i - 1;
		if (buffer[i] == '1')
			result += 1 << power;
		i++;
	}
	return ((char)result);
}

int	ft_client_str(siginfo_t *info)
{
	char	letter;

	letter = ft_convertion(g_server.str_bits, 8);
	if (!letter)
	{
		ft_error(-1, info);
		return (-1);
	}
	else if (letter == 0x04)
	{
		write(1, "\nI'm done doin this:)\n", 23);
		kill(info->si_pid, SIGUSR1);
		g_server.stop = 1;
		g_server.pid = -1;
	}
	else
		write(1, &letter, 1);
	ft_init_clients();
	return (0);
}
