# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 17:12:33 by bhielsch          #+#    #+#              #
#    Updated: 2022/11/29 17:12:35 by bhielsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

UTILSNAME = utils.a
UTILSDIR = utils/
UTILS = $(addprefix $(UTILSDIR), $(UTILSNAME))

CFLAGS = -Wall -Werror -Wextra

CC = cc

C_SRC = client.c
C_SRC_B = client_bonus.c

S_SRC = server.c
S_SRC_B = server_bonus.c

C_OBJ = client.o
C_OBJ_B = client_bonus.o

S_OBJ = server.o
S_OBJ_B = server_bonus.o

all: og bonus

og:	srvr clnt

srvr:		$(S_OBJ)
	make -C utils/
	$(CC) $(CFLAGS) $(S_OBJ) $(UTILS) -o $(SERVER)

clnt:		$(C_OBJ)
	$(CC) $(CFLAGS) $(C_OBJ) $(UTILS) -o $(CLIENT)

bonus: bsrvr bclnt

bsrvr:		$(S_OBJ_B)
	make -C utils/
	$(CC) $(CFLAGS) $(S_OBJ_B) $(UTILS) -o $(SERVER)

bclnt:		$(C_OBJ_B)
	$(CC) $(CFLAGS) $(C_OBJ_B) $(UTILS) -o $(CLIENT)

clean: all
	rm -rf *.o
	@make clean -C utils/

fclean:
	rm -rf *.o
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make fclean -C utils/

re: fclean all
