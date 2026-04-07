NAME        = libftprintf.a
LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRCS        = ft_printf.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_putnbr.c \
			  ft_puthex.c \
			  ft_putptr.c \
			  ft_put_unsigned.c
			  
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re