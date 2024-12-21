# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 18:47:20 by ilevy             #+#    #+#              #
#    Updated: 2024/12/19 13:55:20 by ilevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME:= pipex
BONUS_NAME:= pipex_bonus

#Compiler and flags
CC:= cc
CFLAGS:= -Wall -Wextra -Werror -g3

#Directories
SRC_DIR:= c_files/
OBJ_DIR:= o_files/
B_OBJ_DIR:= b_o_files/
OBLIG_DIR:= Obligatory/
BONUS_DIR:= Bonus/
LIBFT:= libft/

#Absolute files
OBLIG_FILES:= ft_pipex.c ft_utils.c ft_children.c
BONUS_FILES:= ft_pipex_bonus.c ft_utils_bonus.c ft_children_bonus.c
LIBFT_A:= libft.a

#Include dir for .h
INCLUDE:= $(LIBFT)/h_files

# source files

OBLIG_SRC:= $(addprefix $(SRC_DIR)$(OBLIG_DIR), $(OBLIG_FILES))
BONUS_SRC:= $(addprefix $(SRC_DIR)$(BONUS_DIR), $(BONUS_FILES))

#obj files

OBLIG_OBJ:= $(addprefix $(OBJ_DIR), $(OBLIG_FILES:.c=.o))
BONUS_OBJ:= $(addprefix $(B_OBJ_DIR), $(BONUS_FILES:.c=.o))
COMMON_OBJ := $(OBJ_DIR)ft_utils.o $(OBJ_DIR)ft_children.o
#libft.a
LIB:= $(LIBFT)$(LIBFT_A)

# Commands to give.

all:	$(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(OBLIG_OBJ) $(BONUS_OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(COMMON_OBJ) $(LIB) -o $(BONUS_NAME)
	@echo "Compiled $(BONUS_NAME)!"

$(NAME):	$(OBLIG_OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBLIG_OBJ) $(LIB) -o $(NAME)
	@echo "Compiled $(NAME)!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(B_OBJ_DIR):
	@mkdir -p $(B_OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)$(OBLIG_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "Compiled the oblig c files into o files!"

$(B_OBJ_DIR)%.o:	$(SRC_DIR)$(BONUS_DIR)%.c | $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@echo "Compiled the bonus c files into o files!"

clean:
	@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "Cleaned o_files and libft!"

fclean:	clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT)
	@echo "Cleaned .a files and pipex!"

re:	fclean all

.PHONY: all bonus clean fclean re
