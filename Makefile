# ### COMPILATION ###
# CC			= gcc
# FLAGS		= -Wall -Wextra -Werror
# FRAMEWORKS	= -framework OpenGL -framework AppKit

# ### EXECUTABLE ###
# NAME   = fdf

# ### INCLUDES ###
# OBJ_PATH  = ./objs
# HEADER = ./include
# SRC_PATH  = ./src
# LIBFT  = libft
# MLX  = libmlx

# ### SOURCE FILES ###
# SOURCES = main.c \
# 			utils.c \
# 			event.c \
# 			fdf_design.c \
# 			map_parsing.c \
# 			main.c

# ### OBJECTS ###

# SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
# OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

# ### COLORS ###
# NOC         = \033[0m
# BOLD        = \033[1m
# UNDERLINE   = \033[4m
# BLACK       = \033[1;30m
# RED         = \033[1;31m
# GREEN       = \033[1;32m
# YELLOW      = \033[1;33m
# BLUE        = \033[1;34m
# VIOLET      = \033[1;35m
# CYAN        = \033[1;36m
# WHITE       = \033[1;37m

# ### RULES ###

# all: lib tmp $(NAME)

# lib:
# 	@echo "$(GREEN)Creating lib files$(CYAN)"
# 	@make -C $(LIBFT)
# 	@make -C $(MLX)

# $(NAME): $(OBJS)
# 	$(CC) $(FLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx $(FRAMEWORKS) -o $(NAME)
# 	@echo "$(GREEN)Project successfully compiled"

# tmp:
# 	@mkdir -p objs

# $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
# 	@$(CC) $(FLAGS) -c -o $@ $<
# 	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

# clean:
# 	@echo "$(GREEN)Supressing libraries files$(CYAN)"
# 	@make clean -C $(LIBFT)
# 	@rm -rf $(OBJ_PATH)

# fclean:
# 	@echo "$(GREEN)Supressing libraries files$(CYAN)"
# 	@rm -rf $(OBJ_PATH)
# 	@rm -f $(NAME)
# 	@make fclean -C $(LIBFT)

# re: fclean
# 	@$(MAKE) all -j

# .PHONY: temporary, re, fclean, clean

CC			= gcc
FLAGS		= -Wall -Wextra -Werror -o3 -g3
LIBFT		= -L./libft -lft
# MLXLIB		= -I ./minilibx -L ./minilibx -lmlx 
FRAMEWORK	= -framework OpenGL -framework AppKit
INCLUDES	= -I libft/include/ -I includes/ -I minilibx/
SRCS_PATH	= ./src

NAME 		= fdf

SRC 	=	main.c \
			utils.c \
			event.c \
			fdf_design.c \
			map_parsing.c

SRCS 	= 	$(addprefix $(SRCS_PATH)/,$(SRC))
OBJS	=	$(SRCS:.c=.o)

_BLUE	=	\e[34m
_PURPLE	=	\e[35m
_CYAN	=	\e[36m
_END	=	\e[0m

%.o: %.c
			@printf "FDF object : $(_BLUE)%-33.33s\r$(_END)" $@
			@${CC} ${CFLAGS} $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C ./libft
			@$(MAKE) -C ./minilibx
			mv ./minilibx/libmlx.dylib .
			@printf "\nfdf objects	[$(_BLUE)✓$(_END)]\n"
			@gcc $(FLAGS) $(OBJS) libmlx.dylib $(INCLUDES) $(LIBFT)  -o $(NAME) $(FRAMEWORK)
			@printf "fdf		[$(_BLUE)✓$(_END)]\n"

all : 		$(NAME)

re:			clean
			$(MAKE) $(NAME)

clean :
			@rm -rf $(OBJS) $(NAME)
			@rm ./libmlx.dylib
			@printf "$(_PURPLE)FDF object	deleted$(_END)\n"

fclean :	clean
			@$(MAKE) fclean -C ./libft
			@$(MAKE) clean -C ./minilibx
			@rm -rf $(NAME)
			@printf "$(_PURPLE)fdf		deleted$(_END)\n"

PHONY : re all clean fclean