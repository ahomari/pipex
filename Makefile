LIBC		= ar -rcs
FLAGS		= -Wall -Wextra -Werror
CC			= cc
RM			= rm -rf
NAME		= pipex.a


HEAD		= pipex.h
PATH_H		= include/
HEADER		= ${addprefix ${PATH_H}, ${HEAD}}

SRC_FUNC	= ft_calloc.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strcmp.c ft_substr.c 
PATH_F		= func/
FUNC_S		= ${addprefix ${PATH_F}, ${SRC_FUNC}}
F_OBJ		= ${FUNC_S:.c=.o}

SRC_MAN		= pipex.c ft_childs.c error_msg.c
PATH_M		= mandatory/
FUNC_M		= ${addprefix ${PATH_M}, ${SRC_MAN}}
S_OBJ		= ${FUNC_M:.c=.o}


%.o: %.c	${HEADER} Makefile
			${CC} ${FLAGS} -c $< -o $@

${NAME}:	${F_OBJ} ${S_OBJ}
			@${CC} ${F_OBJ} ${S_OBJ}
			@echo "${GREEN}=======> ${NAME} created! <=======${DEFAULT}"

all:		${NAME}

clean:
			@${RM} ${F_OBJ}
			@${RM} ${S_OBJ}
			@echo "${YELLOW}=======> object files deleted! <=======${DEFAULT}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${RED}=======> all deleted! <=======${DEFAULT}"

re: 		fclean all

.PHONY: 	fclean all re  clean

#COLORS

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m