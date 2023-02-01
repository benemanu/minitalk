NAME = utils.a

SRC = ft_print_c.c ft_print_hexlow.c ft_print_hexup.c ft_print_int.c ft_print_p.c\
	ft_print_str.c ft_print_u.c ft_printf.c ft_atoi.c

OBJ = $(SRC:.c=.o);

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs utils.a *.o

clean:
	$(RM) *.o

%.o: %.c
	$(CC) -c $(CFLAGS) $?

fclean:
	$(RM) *.o
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
