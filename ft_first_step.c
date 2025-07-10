/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:12:52 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:13:34 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_first_step(char *server_pid, char *str)
{
	int	i;

	i = 0;
	ft_struct_definition();
	i = strlen(server_pid);
	if (i < 1 || i > 7)
		return (-1);
	i = 0;
	while (server_pid[i])
	{
		if (ft_strisalpha(&server_pid[i]) == -1)
			return (-1);
		i++;
	}
	g_client.pid = ft_atoi(server_pid);
	g_client.str = str;
	ft_bit_by_bit();
	return (0);
}
