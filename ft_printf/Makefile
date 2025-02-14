CC			= 	cc
NAME		=	libftprintf.a
CFLAGS		= 	-Wall -Wextra -Werror
INCLUDE_DIR	:= 	./includes
OBJS_DIR	:=	objs
SRCS_DIR	:=	./srcs
SRCS		:=	$(SRCS_DIR)/ft_printf.c \
				$(SRCS_DIR)/ft_print_pointer.c \
				$(SRCS_DIR)/utils.c \
				$(SRCS_DIR)/ft_putnbr_base.c \
				$(SRCS_DIR)/ft_print_hex.c \
				$(SRCS_DIR)/ft_print_unsigned.c
				
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADERS		:=	$(INCLUDE_DIR)/ft_printf.h $(INCLUDE_DIR)/libft.h

all:$(NAME)

$(NAME):makelibft $(OBJS) 
	@ cp libft/libft.a $@
	@ ar rcs  $@ $(OBJS)

makelibft:
	@ make --no-print-directory -C libft all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) Makefile
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -g -I $(INCLUDE_DIR) -c -o $@  $< 

clean: 
	@ rm -rf $(OBJS_DIR)
	@ make --no-print-directory -C libft clean

fclean: clean
	@ rm -f libftprintf.a
	@ make  --no-print-directory -C libft fclean

re: fclean all

.PHONY: all clean fclean re makelibft
