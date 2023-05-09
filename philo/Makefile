SRCS		=	srcs/philosophers.c								\
				srcs/parsing/argv.c								\
				srcs/initialization/data.c						\
				srcs/program/setup.c							\
				srcs/utils/free.c								\
				srcs/utils/libft/ft_calloc.c					\

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