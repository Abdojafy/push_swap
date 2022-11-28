# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 12:18:06 by ajafy             #+#    #+#              #
#    Updated: 2022/07/01 21:39:38 by ajafy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = push_swap.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c
		
SRCB = checker.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c\
		push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

CC = gcc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

PRINTF_DIR = ft_printf/

LIBFT = Libft/libft.a 

LIBFT_DIR = Libft/

HEADER = push_swap.h

NAME_BONUS = checker

all : $(NAME)

$(NAME) : $(OBJ) $(PRINTF) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(SRC) -o $(NAME) 
	@echo "Push_Swap Maked"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "Printf Maked"

$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@echo "Libft Maked"
	
clean :
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ) 
	@rm -rf $(OBJB) 
	@echo "Clean"

fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJB) $(PRINTF) $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(SRCB) -o $(NAME_BONUS) 
	@echo "Push_Swap Bonus Maked"

	
re : fclean all
