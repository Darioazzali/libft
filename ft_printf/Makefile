CC			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror
INCLUDE_DIR	:= 	./includes
OBJS_DIR	:=	objs
SRCS_DIR	:=	./srcs
LIBFT_DIR	:=	..
LIBFT_I		:=	..
SRCS		:=	$(SRCS_DIR)/ft_printf.c \
				$(SRCS_DIR)/ft_print_pointer.c \
				$(SRCS_DIR)/ft_printf_utils.c \
				$(SRCS_DIR)/ft_putnbr_base.c \
				$(SRCS_DIR)/ft_print_hex.c \
				$(SRCS_DIR)/ft_print_unsigned.c
				
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADERS		:=	$(INCLUDE_DIR)/ft_printf.h $(LIBFT_I)/libft.h

all: $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) Makefile
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -g -I $(INCLUDE_DIR) -I $(LIBFT_I) -c -o $@  $< 

clean: 
	 rm -rf $(OBJS_DIR)

fclean: clean
	@ rm -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re
