
SRCS		=	srcs/philosophers.c								\
				srcs/verification.c								\
				srcs/setup.c									\
				srcs/utils.c									\
				srcs/print.c									\

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

# CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=

NAME		=	philo

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re