NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs
RM			= rm -f

INCS		= libft.h
SRCS		= ft_atoi.c get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) $(INCS)
			$(LIB)	$(NAME) $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
