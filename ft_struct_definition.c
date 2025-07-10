/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:08:43 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/27 16:09:44 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_struct_definition(void)
{
	g_client.pid = 0;
	g_client.index = 0;
	g_client.str = NULL;
	g_client.eot = 0;
	g_client.j = 0;
	g_client.end = 0;
	ft_memset(g_client.buffer, '0', 8);
}
