/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:28:16 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:31:03 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	g_client;

void	ft_signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		usleep(50);
		if (g_client.end == 1)
		{
			ft_printf("SUCCESS \n");
			exit(EXIT_SUCCESS);
		}
		ft_bit_by_bit();
		return ;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("THERES WAS AN ERROR WITH THE SERVER \n");
		exit(EXIT_FAILURE);
		return ;
	}
}
