# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 22:02:36 by barjimen          #+#    #+#              #
#    Updated: 2024/10/19 22:04:51 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- First Part ----------------------------------
#--- Executables
 
	NAME	:= push_swap

#--- Folders

	SRC_DIR		:=		src/
	OBJ_DIR		:=		obj/
	LIB_DIR		:=		lib/
	INC_DIR		:=		inc/
	LFT_DIR		:=		$(LIB_DIR)Libft/

#--- Compile

	cc			:=		gcc
	CFLAGS		:=		-g -Wall -Wextra -Werror -fsanitize=address
	HEADER		:=		-I$(INC_DIR) -I$(LFT_DIR)

#--- .a LIBFT

	LIBFT		:=		$(LFT_DIR)libft.a

#--- .C
	
	SRC_FILES	:=		main  			 		\
						automata/aut_actions	\
						automata/aut_init		\
						automata/aut_main		\
						back_list				\
						swap					\
						rotate					\
						check_list				\
						order_nb				\
						calculate_cost			\
						order_more				\
						move_and_pairs			\
						spin_stack				\
						utils					\

#--- File variables

	SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
	OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
	DEPS		=		$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
	INCS		=		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

#--- Commands

RM				=		rm -f

#--- Cache

OBJF			=		.cache_exists_c

#---------------------------------- Second Part ----------------------------------
default:	
			@$(MAKE) $(NAME) 
			
all:	
		@$(MAKE) $(NAME)
#		@$(MAKE) $(NAME_B)

makelibs:
			@$(MAKE) -C $(LFT_DIR)

-include	${DEPS}
$(NAME):	$(OBJ) makelibs
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

#bonus:
#			@$(MAKE) $(NAME_B)

#-include	${DEPS_B}
#$(NAME_B):	$(OBJ_B) makelibs $(mlx)
#			@$(CC) $(CFLAGS) $(OBJ_B) $(MLXCC) $(LIBFT) -o $(NAME_B)

#$(OBJ_DIR_B)%.o:	$(BONUS_DIR)%.c $(INCS) | $(OBJF_B)
#			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJF)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@
		
#$(OBJF_B):
#			@mkdir -p $(OBJ_DIR_B)


$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/automata
			
			
clean:
			@make clean -sC $(LFT_DIR)
			@$(RM) -rf $(OBJ_DIR)
#			@$(RM) -rf $(OBJ_DIR_B)

fclean:		clean
			@$(RM) -f $(NAME)
#			@$(RM) -f $(NAME_B)
			@make fclean -sC $(LFT_DIR)

re:			fclean
			@$(MAKE)

norminette:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: default all makelibs bonus clean fclean re norminette