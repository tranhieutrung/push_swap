# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 18:50:13 by hitran            #+#    #+#              #
#    Updated: 2024/07/08 15:54:19 by hitran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
INCLUDES 		= -I./includes -I./mylib/includes

# Directories
MAN_DIR 		= ./mandatory
BONUS_DIR		= ./bonus
MYLIB_DIR	 	= ./mylib

# Source's directories
MAIN_DIR 		= main
ALGO_DIR 		= algo
STACK_DIR 		= parse
UTILS_DIR 		= utils
OPS_DIR		 	= ops

# Source files by directory
MAIN_FILES 		= 	main.c
ALGO_FILES 		= 	push_a2b.c				\
					push_b2a.c 				\
					sort_three.c 			\
					sort_five.c
STACK_FILES 	= 	parse_input.c 			\
					put_in_stack.c 			\
					split_args.c
UTILS_FILES 	= 	utils.c					\
					stack_utils.c			\
					chunk_utils.c
OPS_FILES		= 	swap.c 					\
					push.c 					\
					rotate.c 				\
					reverse_rotate.c

MAIN_FILES_BN 	= 	main_bonus.c
ALGO_FILES_BN	=	checker_bonus.c
STACK_FILES_BN	= 	parse_input_bonus.c 	\
					put_in_stack_bonus.c 	\
					split_args_bonus.c
UTILS_FILES_BN 	= 	utils_bonus.c			\
					stack_utils_bonus.c		\
					read_line_bonus.c
OPS_FILES_BN	= 	push_swap_bonus.c		\
					rotate_bonus.c

PUSH_SWAP_SRCS	= 	$(addprefix $(MAN_DIR)/$(MAIN_DIR)/, $(MAIN_FILES)) \
					$(addprefix $(MAN_DIR)/$(ALGO_DIR)/, $(ALGO_FILES)) \
					$(addprefix $(MAN_DIR)/$(STACK_DIR)/, $(STACK_FILES)) \
					$(addprefix $(MAN_DIR)/$(UTILS_DIR)/, $(UTILS_FILES)) \
					$(addprefix $(MAN_DIR)/$(OPS_DIR)/, $(OPS_FILES))

CHECKER_SRCS	=	$(addprefix $(BONUS_DIR)/$(MAIN_DIR)/, $(MAIN_FILES_BN)) \
					$(addprefix $(BONUS_DIR)/$(ALGO_DIR)/, $(ALGO_FILES_BN)) \
					$(addprefix $(BONUS_DIR)/$(STACK_DIR)/, $(STACK_FILES_BN)) \
					$(addprefix $(BONUS_DIR)/$(UTILS_DIR)/, $(UTILS_FILES_BN)) \
					$(addprefix $(BONUS_DIR)/$(OPS_DIR)/, $(OPS_FILES_BN))

# Library
MYLIB 			= $(MYLIB_DIR)/mylib.a

# Executables
NAME 			= push_swap
BONUS 			= checker

# Targets
all: $(NAME)

$(NAME): $(MYLIB) $(PUSH_SWAP_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_SRCS) $(MYLIB) -o $(NAME)

bonus: .bonus
.bonus: $(MYLIB) $(CHECKER_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(CHECKER_SRCS) $(MYLIB) -o $(BONUS)
	@touch .bonus

$(MYLIB):
	$(MAKE) -C $(MYLIB_DIR)

clean:
	$(MAKE) clean -C $(MYLIB_DIR)


fclean: clean
	$(MAKE) fclean -C $(MYLIB_DIR)
	$(RM) $(NAME) $(BONUS) .bonus
	
re: fclean all

.PHONY: all clean fclean re bonus