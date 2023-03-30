
SRCS		=	srcs/philosophers.c								\
				srcs/verification.c								\
				srcs/setup.c									\
				srcs/utils.c									\
				srcs/print.c									\
				srcs/one_philosopher.c							\
				srcs/more_philosophers.c						\
				srcs/init_philosophers.c						\
				srcs/mutex.c									\
				srcs/actions.c									\

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

# CFLAGS		=	-Wall -Wextra -Werror
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