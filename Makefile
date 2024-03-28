# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:25:02 by lnicolau          #+#    #+#              #
#    Updated: 2024/03/26 18:25:03 by lnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_C = client
NAME_S = server

CC = cc 
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_S = server.c
OBJ_S = $(SRC_S:.c=.o)
SRC_C = client.c
OBJ_C = $(SRC_C:.c=.o)


%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@

all : server client
server: libft $(OBJ_S)
		@ $(CC) $(FLAGS) -o $(NAME_S) $(OBJ_S) libft/*.o 

client: libft $(OBJ_C)
		@ $(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) libft/*.o

libft:
		@ make -C libft/

clean:
		@ $(RM) $(OBJ_S) $(OBJ_C) 
		@ make clean -C libft/

fclean: clean
		@ $(RM) $(NAME_S) $(NAME_C)
		@ make fclean -C libft/

re: fclean all

.PHONY: all libft clean fclean re