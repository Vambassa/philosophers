NAME	=	philo

SRCS	=	./srcs/dining.c ./srcs/init_structure.c ./srcs/life_monitoring.c \
			./srcs/main.c ./srcs/simulation.c ./srcs/utils.c ./srcs/write_message.c

OBJS	=	$(patsubst %.c,%.o,$(SRCS))
D_FILES	=	$(patsubst %.c,%.d,$(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@ -MMD

clean:
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include ${D_FILES}