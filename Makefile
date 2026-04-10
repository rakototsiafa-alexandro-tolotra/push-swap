# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     :+:      :+:    :+:    #
#    By: arakotot <arakotot@student.42antananari      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 10:07:48 by herasoan          #+#    #+#              #
#    Updated: 2026/03/18 21:20:27 by arakotot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap


CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g


LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

# Fichiers sources (Tous à la racine selon ta capture d'écran)
SRCS        = main.c \
			  options.c \
              parsing.c parsing_utils.c \
              error_manager.c \
			  bench.c \
			  bench_utils.c \
              stack_init.c stack_utils.c \
              disorder.c \
              operations_push.c operations_swap.c \
              operations_rotate.c operations_rev_rotate.c \
			  sort_simple.c sort_simple_utils.c sort_medium.c \
			  sort_medium_utils.c sort_complex.c sort_adaptive.c \

OBJS        = $(SRCS:.c=.o)

# Includes (Le header est à la racine '.')
INCLUDES    = -I . -I $(LIBFT_DIR) -I $(PRINTF_DIR)

# Linkage (Ordre important : printf dépend souvent de libft)
LFLAGS      = -L $(PRINTF_DIR) -lftprintf -L $(LIBFT_DIR) -lft

# Couleurs pour le terminal
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

# Règles principales
all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation de $(NAME) terminée !$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@echo "$(RED)Objets supprimés.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@echo "$(RED)Exécutable et librairies supprimés.$(RESET)"

re: fclean all

.PHONY: all clean fclean re