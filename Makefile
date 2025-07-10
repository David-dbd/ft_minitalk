# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 15:06:59 by davdiaz-          #+#    #+#              #
#    Updated: 2025/05/27 17:12:19 by davdiaz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= client
NAME_TWO = server
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
FUNC_CLIENT 	= client.c ft_first_step.c ft_strisalpha.c client_main.c ft_struct_definition.c ft_strbinary.c ft_bit_by_bit.c
FUNC_SERVER     = ft_buffer_bits.c ft_client_str.c server.c ft_init_clients.c ft_error.c
OBJS_CLIENT = $(FUNC_CLIENT:.c=.o)
OBJS_SERVER = $(FUNC_SERVER:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(PRINTF) $(NAME) $(NAME_TWO)
# Compila Libft antes de compilar

$(PRINTF): $(LIBFT)
	@$(MAKE) -C $(PRINTF_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	@echo "Cliente compilado correctamente."
	
$(NAME_TWO): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_TWO) $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	@echo "server compilado correctamente."

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@rm -f $(LIBFT_DIR)/*.o $(PRINTF_DIR)/*.o
	@echo "Archivos objeto eliminados."

fclean: clean
	@rm -f $(NAME) $(NAME_TWO)
	@echo "Ejecutables eliminados."

re: fclean all

.PHONY: all clean fclean re comp
