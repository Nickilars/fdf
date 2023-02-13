CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC_FOLDER	= ./src/

GNL_SRC_FOLDER	= ./src/gnl/

PRINTF_SRC_FOLDER	= ./src/ft_printf/

SRCS	= $(SRC_FOLDER)ft_isalpha.c \
			$(SRC_FOLDER)ft_isdigit.c \
			$(SRC_FOLDER)ft_isalnum.c \
			$(SRC_FOLDER)ft_isascii.c \
			$(SRC_FOLDER)ft_isprint.c \
			$(SRC_FOLDER)ft_tolower.c \
			$(SRC_FOLDER)ft_toupper.c \
			$(SRC_FOLDER)ft_atoi.c \
			$(SRC_FOLDER)ft_strncmp.c \
			$(SRC_FOLDER)ft_memcmp.c \
			$(SRC_FOLDER)ft_itoa.c \
			$(SRC_FOLDER)ft_strdup.c \
			$(SRC_FOLDER)ft_strchr.c \
			$(SRC_FOLDER)ft_nbrlen_d.c \
			$(SRC_FOLDER)ft_nbrlen_exa.c \
			$(SRC_FOLDER)ft_strrchr.c \
			$(SRC_FOLDER)ft_strlen.c \
			$(SRC_FOLDER)ft_islower.c \
			$(SRC_FOLDER)ft_isupper.c \
			$(SRC_FOLDER)ft_free_2da.c \
			$(SRC_FOLDER)ft_free_arrays.c \
			$(SRC_FOLDER)ft_strlcpy.c \
			$(SRC_FOLDER)ft_strlcat.c \
			$(SRC_FOLDER)ft_split.c \
			$(SRC_FOLDER)ft_strjoin.c \
			$(SRC_FOLDER)ft_strtrim.c \
			$(SRC_FOLDER)ft_strmapi.c \
			$(SRC_FOLDER)ft_substr.c \
			$(SRC_FOLDER)ft_strnstr.c \
			$(SRC_FOLDER)ft_bzero.c \
			$(SRC_FOLDER)ft_nbrlen_b.c \
			$(SRC_FOLDER)ft_itob.c \
			$(SRC_FOLDER)ft_btoi.c \
			$(SRC_FOLDER)ft_atob.c \
			$(SRC_FOLDER)ft_power.c \
			$(SRC_FOLDER)ft_putchar_fd.c \
			$(SRC_FOLDER)ft_putstr_fd.c \
			$(SRC_FOLDER)ft_putnbr_fd.c \
			$(SRC_FOLDER)ft_putendl_fd.c \
			$(SRC_FOLDER)ft_calloc.c \
			$(SRC_FOLDER)ft_memset.c \
			$(SRC_FOLDER)ft_memchr.c \
			$(SRC_FOLDER)ft_memcpy.c \
			$(SRC_FOLDER)ft_memmove.c \
			$(SRC_FOLDER)ft_striteri.c \
			$(SRC_FOLDER)ft_lstnew_bonus.c \
			$(SRC_FOLDER)ft_lstadd_front_bonus.c \
			$(SRC_FOLDER)ft_lstsize_bonus.c \
			$(SRC_FOLDER)ft_lstlast_bonus.c \
			$(SRC_FOLDER)ft_lstadd_back_bonus.c \
			$(SRC_FOLDER)ft_lstdelone_bonus.c \
			$(SRC_FOLDER)ft_lstclear_bonus.c \
			$(SRC_FOLDER)ft_lstiter_bonus.c

SRCS_GNL	= $(GNL_SRC_FOLDER)get_next_line.c \
				$(GNL_SRC_FOLDER)get_next_line_utils.c

SRCS_PRINTF	= $(PRINTF_SRC_FOLDER)ft_printf.c \
				$(PRINTF_SRC_FOLDER)ft_print_c.c \
				$(PRINTF_SRC_FOLDER)ft_print_d.c \
				$(PRINTF_SRC_FOLDER)ft_print_hex.c \
				$(PRINTF_SRC_FOLDER)ft_print_p.c \
				$(PRINTF_SRC_FOLDER)ft_print_s.c \
				$(PRINTF_SRC_FOLDER)ft_print_u.c

OBJS	= $(SRCS:.c=.o) $(SRCS_GNL:.c=.o) $(SRCS_PRINTF:.c=.o)

NAME	= libft.a

RM		= rm -f

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

$(NAME) : $(OBJS)
		ar -rs $(NAME) $(OBJS)

re : fclean $(NAME)

clean :
		$(RM) *.o $(SRC_FOLDER)*.o $(GNL_SRC_FOLDER)*.o $(PRINTF_SRC_FOLDER)*.o

fclean : clean
		$(RM) $(NAME)

.PHONY: all re clean fclean