#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 03:34:36 by mbiliaie          #+#    #+#              #
#    Updated: 2019/02/26 03:34:55 by mbiliaie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC 		= clang
NAME 	= lem-in
CFLAGS 	= -Wall -Werror -O3 -Wextra

SRC_DIR = src/
HDR_DIR = include/
OUT_DIR = obj/

L_NAME 	= libft
LIB_DIR = $(L_NAME)/
LIB_HDR = $(LIB_DIR)
LIBFT 	= $(LIB_DIR)$(L_NAME).a
LIB 	= -lft -L$(LIB_DIR)

INCL 	= -I$(HDR_DIR) -I$(LIB_HDR)
HDR 	= include/lem_in.h

SRC 	=	algo_launcher.c\
			blind_alleys_handler.c\
			do_main_algo_1p.c\
			do_main_algo_2p.c\
			look_for_objects.c\
			general_dispatch.c\
			main.c\
			internal_checker_1p.c\
			internal_checker_2p.c\
			internal_checker_3p.c\
			memory_clearence_1p.c\
			memory_clearence_2p.c\
			prepare_ways_and_moves.c\
			places_for_moves.c\
			proceed_handling_ways_and_moves.c\
			process_gnl_input_and_ways.c\
			provide_places_and_strings_output.c\
			provide_ways_output.c\
			separations_handler_1p.c\
			separations_handler_2p.c\
			separations_utilities.c\
			error_management.c\
			uploader_aggregated_1p.c\
			uploader_aggregated_2p.c\
			uploader_check_vertices.c\
			uploader_utilities_1p.c\
			uploader_utilities_2p.c

OBJ	= $(addprefix $(OUT_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OUT_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(INCL) $(OBJ) -o $(NAME)
	@echo "$(L_NAME).a is ready!"
	@echo "--- --- --- --- --- --- --- ---"
	@echo "obj directory has been made"
	@echo "o-files have been produced"
	@echo "--- --- --- --- --- --- --- ---"
	@echo "$(NAME) is ready!"

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HDR)
	@$(CC) $(CFLAGS) -c $(INCL) $< -o $@

$(LIBFT):
	@echo "--- --- --- --- --- --- --- ---"
	@echo "compiling" $(L_NAME)"..."
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@echo "$(L_NAME).a has been removed"
	@rm -rf $(OUT_DIR)
	@echo "obj directory has been removed"
	@echo "o-files have been removed"

fclean: clean
	@rm -f $(LIBFT)
	@echo "--- --- --- --- --- --- --- ---"
	@rm -f $(NAME)
	@echo "$(NAME) has been removed"

re: fclean all

.PHONY: all clean fclean re   