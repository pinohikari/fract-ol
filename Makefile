NAME = fractol

SRCS := mandelbrot.c\
		close.c\
		main.c\
		mouse.c\
		julia.c\
		utils.c\
		utils2.c

OBJS	= $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: 	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY :  all clean fclean re
