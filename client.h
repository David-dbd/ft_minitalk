/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:24:43 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:45:42 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include "libftprintf.h"

typedef struct t_client
{
	char	*str;
	char	buffer[8];
	int		pid;
	int		index;
	int		eot;
	int		end;
	int		j;
}	t_client;

extern t_client	g_client;

int		ft_strisalpha(char *str);
int		ft_first_step(char *server_pid, char *str);
int		main(int argc, char *argv[]);
void	ft_signal_handler(int sig);
void	ft_struct_definition(void);
void	ft_strbinary(int nbr, char *buffer);
void	ft_bit_by_bit(void);
#endif
