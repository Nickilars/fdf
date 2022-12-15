CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_printf.c \
		ft_print_c.c \
		ft_print_s.c \
		ft_print_d.c \
		ft_print_hex.c \
		ft_print_p.c \
		ft_print_u.c

OBJ		= $(SRC:.c=.o)

NAME	= ft_printf.a

DEPS	= ft_printf.h

RM		= rm -rf

all :	$(NAME)

%.o :	%.c $(DEPS)
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
		ar -qc $(NAME) $(OBJ)
		ranlib $(NAME)

re : fclean $(NAME)

clean :
		$(RM) *.o

fclean : clean
		$(RM) $(NAME)

.PHONY: all re clean fclean
