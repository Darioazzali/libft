CC=cc
INCLUDE_DIR=..
CFLAGS=-Wall -Wextra -I$(INCLUDE_DIR)
SRCS_DIR:=..
OBJ_DIR:=objs
tests_function:=atoi \
				bzero \
				calloc \
				count_words \
				isalnum \
				isalpha \
				isascii \
				isdigit \
				isprint \
				itoa \
				lstadd_back_bonus \
				lstadd_front_bonus \
				lstclear_bonus \
				lstdelone_bonus \
				lstiter_bonus \
				lstlast_bonus \
				lstmap_bonus \
				lstnew_bonus \
				lstsize_bonus \
				memchr \
				memcmp \
				memcpy \
				memmove \
				memset \
				putchar_fd \
				putnbr_fd \
				putstr_fd \
				split \
				split_malloc \
				strchr \
				strdup \
				striteri \
				strjoin \
				strlcat \
				strlcpy \
				strlen \
				strmapi \
				strncmp \
				strnstr \
				strrchr \
				strtrim \
				substr \
				tolower \
				toupper 
OBJS:=$(tests_function:%=$(OBJ_DIR)/%.o)		

special_tests := strlcat strlcpy strnstr split_malloc
standard_tests := $(filter-out $(special_tests),$(tests_function))


test: makelft $(tests_function) 
	@ for test in $(tests_function); \
	do \
	if ! ./$$test 1>/dev/null; then \
	echo -e "\e[31m $$test: failed\e[0m"; \
	else \
	echo -e "\e[32m $$test: OK\e[0m"; \
	fi; \
	rm $$test; \
	done

makelft:
	@ make -C .. bonus

strnstr: strnstr.c $(SRCS_DIR)/ft_strnstr.c $(SRCS_DIR)/ft_strlen.c
	@ $(CC) $(CFLAGS) -I.. $(shell pkg-config --cflags --libs libbsd)   -o $@ $^ -g -L.. -lft

strlcpy: strlcpy.c $(SRCS_DIR)/ft_strlcpy.c $(SRCS_DIR)/ft_strlen.c $(OBJ_DIR)/helpers.o
	@ $(CC) $(CFLAGS) -I.. $(shell pkg-config --cflags --libs libbsd)   -o $@ $^ -g -L.. -lft

strlcat: strlcat.c $(SRCS_DIR)/ft_strlcat.c $(SRCS_DIR)/ft_strlen.c
	@ $(CC) $(CFLAGS) -I.. $(shell pkg-config --cflags --libs libbsd)   -o $@ $^ -g

# atoi: atoi.o helpers.o
# 	@ $(CC) $(CFLAGS) -I.. -o $@ $^ -g -L.. -lft

split_malloc: split_malloc.c 
	@ $(CC) $(CFLAGS) -I.. -o $@ $^ -g

# calloc: calloc.c $(SRCS_DIR)/ft_calloc.c $(SRCS_DIR)/ft_bzero.c $(SRCS_DIR)/ft_memset.c
# 	@ $(CC) $(CFLAGS) -I.. -o $@ $^ -g


$(standard_tests):%: $(OBJ_DIR)/%.o ../libft.a $(OBJ_DIR)/helpers.o
	@ $(CC) $(CFLAGS) -g -I.. -I.  -o $@ $^ -L.. -lft

$(OBJ_DIR)/%.o: %.c  helpers.c  helpers.h
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -g -c -I.. -I. -o $@ $<

$(OBJ_DIR)/helpers.o: helpers.c helpers.h
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -g -c -I.. -I. -o $@ $<

clean:
	@ rm -f $(tests_function)
	@ rm -f $(OBJ_DIR)/*

.PHONY : test clean split_malloc 
