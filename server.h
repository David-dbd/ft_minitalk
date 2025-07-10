/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:43 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:33:03 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"
# include "libftprintf.h"

typedef struct client_info
{
	char	str_bits[8];
	int		index;
	int		stop;
	int		pid;
}	t_client;

extern t_client	g_server;

int		ft_client_str(siginfo_t *info);
int		ft_buffer_bits(int sig, siginfo_t *info);
int		server_main(void);
int		ft_error(int ptr, siginfo_t *info);
void	ft_init_clients(void);
#endif
