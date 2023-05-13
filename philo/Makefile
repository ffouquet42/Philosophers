SRCS		=	srcs/philosophers.c								\
				srcs/parsing/argv.c								\
				srcs/initialization/data.c						\
				srcs/initialization/mutex.c						\
				srcs/initialization/philo.c						\
				srcs/program/setup.c							\
				srcs/program/one_philo.c						\
				srcs/program/death.c							\
				srcs/program/eat.c								\
				srcs/program/routine.c							\
				srcs/utils/free.c								\
				srcs/utils/time.c								\
				srcs/utils/display.c							\
				srcs/utils/libft/ft_calloc.c					\
				srcs/utils/libft/ft_atoi.c						\

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

RM			=	rm -f

#CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=thread
CFLAGS		=

NAME		=	philo

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re