/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:13:58 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:14:16 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_error(int ptr, siginfo_t *info)
{
	if (ptr == -1)
	{
		kill(info->si_pid, SIGUSR2);
		ft_init_clients();
		return (-1);
	}
	return (0);
}
