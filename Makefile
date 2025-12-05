# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 14:52:34 by toroman           #+#    #+#              #
#    Updated: 2025/11/18 15:17:18 by toroman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parsing/utils.c\
		parsing/main.c 

OBJS = ${SRCS:.c=.o}
NAME = cube3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./utils/utils.a


# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Barre de chargement compacte et colorée
define progress_bar
	@i=0; \
	while [ $$i -le 20 ]; do \
		printf "${BLUE}\r[${GREEN}%-20s${BLUE}]${YELLOW} %d%%${RESET}" "$$(printf '▓%.0s' $$(seq 1 $$i))" $$((i*5)); \
		sleep 0.1; \
		i=$$((i+1)); \
	done; \
	echo
endef

all : ${NAME}

${NAME}: ${OBJS}
	@echo "${BLUE}Compilation en cours...${RESET}"
	@$(progress_bar) & \
	PROGRESS_PID=$$!; \
	${MAKE} -C ./utils/ > /dev/null 2>&1; \
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./utils/utils.a; \
	STATUS=$$?; \
	kill $$PROGRESS_PID 2>/dev/null || true; \
	if [ $$STATUS -eq 0 ]; then \
		echo "${GREEN}\nCompilation terminée !${RESET}"; \
	else \
		echo "${RED}\nErreur de compilation !${RESET}"; \
		exit 1; \
	fi

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@${MAKE} clean -C ./utils/ > /dev/null 2>&1
	@${RM} ${OBJS} > /dev/null 2>&1
	@echo "${YELLOW}Nettoyage des fichiers objets terminé.${RESET}"

fclean: clean
	@${RM} ${NAME} ./utils/utils.a > /dev/null 2>&1
	@echo "${RED}Nettoyage complet terminé.${RESET}"

re: fclean all

.PHONY: all clean fclean re
