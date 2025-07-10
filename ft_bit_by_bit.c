/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_by_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:17:47 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:22:23 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ft_eot(void)
{
	char	bit;

	if (g_client.eot == 0)
	{
		g_client.eot = 1;
		g_client.j = 0;
		ft_strbinary(0x04, g_client.buffer);
	}
	if (g_client.j < 8)
	{
		bit = g_client.buffer[g_client.j];
		if (bit == '1')
			kill(g_client.pid, SIGUSR1);
		else
			kill(g_client.pid, SIGUSR2);
		if (g_client.j == 7)
			g_client.end = 1;
		g_client.j++;
	}
}

void	ft_bit_by_bit(void)
{
	char	bit;

	if (g_client.end == 1)
		return ;
	if (g_client.j >= 8)
	{
		g_client.j = 0;
		g_client.index++;
	}
	if (g_client.str[g_client.index] != '\0')
	{
		if (g_client.j == 0)
			ft_strbinary(g_client.str[g_client.index], g_client.buffer);
		bit = g_client.buffer[g_client.j];
		if (bit == '1')
			kill(g_client.pid, SIGUSR1);
		else
			kill(g_client.pid, SIGUSR2);
		g_client.j++;
	}
	else
		ft_eot();
}
