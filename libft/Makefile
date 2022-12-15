CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_itoa.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_strnstr.c \
			ft_bzero.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_calloc.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_striteri.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c

OBJ		= $(SRCS:.c=.o)

NAME	= libft.a

FT_PRTF = ./ft_printf

GNL 	= ./get_next_line

DEPS	= libft.h

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

		$(MAKE) -C $(FT_PRTF)
		cp ./ft_printf/ft_printf.a .
		mv ft_printf.a $(NAME)
		@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

		$(MAKE) -C $(GNL)
		cp ./get_next_line/get_next_line.a .
		mv get_next_line.a $(NAME)
		@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"


		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		@echo "$(GREEN)Project successfully compiled"

		$(MAKE) clean
		@echo "$(YELLOW) *.o deleted"

re : fclean $(NAME)

clean :
		$(RM) *.o
		$(RM) ./ft_printf/*.o
		$(RM) ./get_next_line/*.o

fclean : clean
		$(RM) $(NAME)
		$(RM) ./ft_printf/ft_printf.a
		$(RM) ./get_next_line/get_next_line.a

.PHONY: all re clean fclean