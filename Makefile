FLAGS			= -Wall -Wextra -Werror
CC				= cc
RM				= rm -rf
NAME			= pipex
NAME_BONUS		= pipex_bonus

HEAD			= include/pipex.h include/pipex_bonus.h


SRC_FUNC		= func/ft_calloc.c func/ft_split.c func/ft_strdup.c func/ft_strjoin.c func/ft_strlen.c \
					func/ft_strcmp.c func/ft_substr.c func/ft_strchr.c func/ft_strcpy.c 
F_OBJ			= ${SRC_FUNC:.c=.o}

SRC_MAN			= mandatory/pipex.c mandatory/ft_childs.c mandatory/error_msg.c
S_OBJ			= ${SRC_MAN:.c=.o}

SRC_BONUS_FUNC	= bonus/func/ft_calloc_bonus.c bonus/func/ft_split_bonus.c bonus/func/ft_strdup_bonus.c bonus/func/ft_strjoin_bonus.c \
					bonus/func/ft_strlen_bonus.c bonus/func/ft_strcmp_bonus.c bonus/func/ft_substr_bonus.c bonus/func/ft_strchr_bonus.c \
					bonus/func/ft_strcpy_bonus.c bonus/func/ft_putstr_fd_bonus.c
F_BONUS_OBJ		= ${SRC_BONUS_FUNC:.c=.o}

SRC_BONUS		= bonus/pipex_bonus.c bonus/ft_childs_bonus.c bonus/error_msg_bonus.c bonus/ft_childs_here.c
B_OBJ			= ${SRC_BONUS:.c=.o}

GET_BONUS		= gnl/get_next_line.c gnl/ft_strjoinn.c
BONUS_OBJ_GET	= ${GET_BONUS:.c=.o}

%.o: %.c		${HEAD} Makefile
				${CC} ${FLAGS} -c $< -o $@

${NAME}:		${F_OBJ} ${S_OBJ}
				@${CC} ${F_OBJ} ${S_OBJ} -o ${NAME}
				@echo "${GREEN}================================${DEFAULT}"
				@echo "${GREEN}=======| ${NAME} Created! |=======${DEFAULT}"
				@echo "${GREEN}================================${DEFAULT}"

all:			${NAME}

bonus : 		${NAME_BONUS} 

${NAME_BONUS}:	${F_BONUS_OBJ} ${BONUS_OBJ_GET} ${B_OBJ}
				@${CC} ${F_BONUS_OBJ} ${BONUS_OBJ_GET} ${B_OBJ} -o ${NAME_BONUS}
				@echo "${GREEN}======================================${DEFAULT}"
				@echo "${GREEN}=======| ${NAME_BONUS} Created! |=======${DEFAULT}"
				@echo "${GREEN}======================================${DEFAULT}"



clean:
				@${RM} ${F_OBJ}
				@${RM} ${S_OBJ}
				@${RM} ${B_OBJ}
				@${RM} ${F_BONUS_OBJ}
				@${RM} ${BONUS_OBJ_GET}
				@echo "${YELLOW}=======================================${DEFAULT}"
				@echo "${YELLOW}=======| Object Files deleted! |=======${DEFAULT}"
				@echo "${YELLOW}=======================================${DEFAULT}"

fclean:			clean
				@${RM} ${NAME} ${NAME_BONUS}
				@echo "${RED}==============================${DEFAULT}"
				@echo "${RED}=======| All Deleted! |=======${DEFAULT}"
				@echo "${RED}==============================${DEFAULT}"

re: 			fclean all

.PHONY: 	fclean all re  clean

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m