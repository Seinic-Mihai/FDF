# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mseinic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/14 11:35:32 by mseinic           #+#    #+#              #
#    Updated: 2016/02/27 11:07:29 by mseinic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_LIST = menu draw parsing get_matrix hooks main putline window_cfg text create_del

HDR_LIST = fdf get_next_line libft

SRC_PATH = ./src/

HDR_PATH = ./includes/

CACHE_PATH = ./cache/

COMPILER = gcc -g

CFLAGS = -Werror -Wextra -Wall

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT := -L libft

LIB_PATH = ./libft/libft.a

#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#
SRC = $(addprefix $(SRC_PATH),$(addsuffix .c,$(SRC_LIST)))
OBJ = $(addprefix $(CACHE_PATH),$(addsuffix .o,$(SRC_LIST)))
HDR = $(addprefix $(HDR_PATH),$(addsuffix .h,$(HDR_LIST)))
INC = $(addprefix -I, $(HDR_PATH))
#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#

#-----------------COLORS------------------#
#-------B = Bolt---------#
#-------I = Intense------#
#-------U = Underline----#
Green	= "\033[0;32m"
Red	= "\033[1;91m"
Yellow	= "\033[0;33m"
END 	= "\033[0m"
#-----------------COLORS------------------#

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C libft
		@echo $(Yellow) " Compiling --> $@ <-- with $(CFLAGS) " $(END)
		@$(COMPILER) $(CFLAGS) $(OBJ) $(INC) \
				$(MLX_FLAGS) $(LIBFT) $(LIB_PATH) -o $(NAME)
		@echo $(Green) " !!! Ready !!!" $(END)

$(CACHE_PATH)%.o:$(SRC_PATH)%.c
		@mkdir -p $(CACHE_PATH)
		@echo $(Green) "Creating $(NAME) : $@ with $< " $(END);
		@$(COMPILER) $(CFLAGS) $(INC) -o $@ -c $<

clean:
		@/bin/rm -rf $(CACHE_PATH)
		@echo $(Red) "Deleting ---->>>> $(CACHE_PATH)" $(END)
fclean: clean
		@/bin/rm -rf $(NAME)
		@echo $(Red) "Deleting ---->>>> $(NAME)" $(END)
re: fclean all

.PHONY: all clean fclean re
