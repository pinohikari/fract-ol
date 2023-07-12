NAME = fractol

SRCS := mandelbrot_ver2.c\
		close.c\
		main.c\
		mouse.c\
		julia_ver2.c\
		utils.c\
		utils2.c

OBJS	= $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: 	$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY :  all clean fclean re
