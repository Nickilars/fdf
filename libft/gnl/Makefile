CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC		= get_next_line.c \
			get_next_line_utils.c

OBJ		= $(SRC:.c=.o)

NAME	= get_next_line.a

DEPS	= get_next_line.h

RM		= rm -rf

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all :	$(NAME)

%.o :	%.c $(DEPS)
		$(CC) $(CFLAGS) -o $@ -c $<
		@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

$(NAME) : $(OBJ)
		ar -qc $(NAME) $(OBJ)
		ranlib $(NAME)
		@echo "$(GREEN)Project successfully compiled"

		$(MAKE) clean
		@echo "$(YELLOW) *.o deleted"

re : fclean $(NAME)

clean :
		$(RM) *.o

fclean : clean
		$(RM) $(NAME)

.PHONY: all re clean fclean