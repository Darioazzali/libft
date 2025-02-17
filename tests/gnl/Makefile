CC					=	cc
gnl_dir				=	../..
CFLAGS				=	-Wall -Wextra -Werror
include_dir 		:=	$(gnl_dir)
tests_src_dir		:=	src
tests				:=	input_files	\
						buff_size	\
						no_allowed	
bonus				:=	input_files_bonus
tests_src			:=	$(tests:%=$(tests_src_dir)/%.c)
tests_obj			:=	$(tests_src:%.c=%.o)
objs_bonus			:= 	$(srcs_bonus:%.c=%.o)
header				:=	$(include_dir)/libft.h
NAME				:=	get_next_line
LIBFT				:=	libft.a
script_dir			:=	scripts
BUFFER_SIZE			::=	1024
inputs				:= 	./input/test1.txt	\
					 	./input/test2.txt	\
					 	./input/test3.txt	\
					 	./input/test4.txt	\
					 	./input/test1_no_newline.txt

help:
	@echo "Usage:\n\
		run ./run_tests.sh"

tests:  $(tests) 

test_buff_size: buff_size $(objs) 
	@$(script_dir)/test_buff_size.sh
	@printf "%-20s \t\e[32mOK\e[0m\n" "Test buffer size"

$(tests): %: $(tests_src_dir)/%.o $(objs)
	@ $(CC) $(CFLAGS) $^ -o $@ -I $(include_dir) -L $(gnl_dir) -lft

$(bonus): %: $(tests_src_dir)/%.o $(objs_bonus)
	@ $(CC) $(CFLAGS) $^ -o $@ -include $(include_dir)

stdin: $(tests_src_dir)/stdin.c $(objs)
	@ls "$(include_dir)"
	@$(CC) $(CFLAGS) -o stdin $^ -I$(include_dir) -L $(gnl_dir) -lft

%.o: %.c $(header) Makefile
	 @$(CC) $(CFLAGS)  -D BUFFER_SIZE=$(BUFFER_SIZE) -I$(include_dir) -c -g -o $@ $<


leak_checks: $(inputs) input_files 
	@for i in $(inputs); do \
		echo -e "\x1b[33mChecking $$i\x1b[0m"; \
	/bin/valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --error-exitcode=1 ./input_files $$i ; \
	done

	
norminette: $(srcs) $(header)
	@norminette --use-gitignore $^

clean:
	@rm -f $(objs)
	@rm -f $(tests)
	@rm -f $(tests_obj)
	@rm -f $(bonus) $(objs_bonus)
	@rm -f stdin
	@rm -f test_*
	@rm	-f $(tests_src_dir)/*.o
	@rm -f vgcore*
	@rm -f valgrind_output*

fclean: clean 

re: fclean tests

.PHONY: test re fclean clean norminette buffer help bonus
