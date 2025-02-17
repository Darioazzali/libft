#!/bin/bash
inputs=(
	test1_no_newline.txt
	test1.txt
	test2.txt
	test3.txt
	test4.txt
)
no_newline=no_newline.txt

quiet=false

function usage() {
	echo "run_tests [-d buffer_size] [-q quiet] [-h help] [FILE]"
	echo ""
	printf "  %-15s\t %s\n" "-d <BUFFER_SIZE>" "compile with a BUFFER_SIZE reading buffer"
	printf "  %-15s\t %s\n" "-q" "quiet mode, suppress output from tests"
	printf "  %-15s\t %s\n" "FILE" "file to test (if not provided, run all tests)"
	echo ""
}

while getopts 'hd:q' flag; do
	case "${flag}" in
	d) buffer_size="${OPTARG}" ;;
	q) quiet=true ;;
	h)
		usage
		exit
		;;
	*) ;;
	esac
done
shift $(($OPTIND - 1))

echo "Compiling tests..."
if [ -z "$buffer_size" ]; then
	buffer_size=1024
else
	make clean
fi
echo "with buffer size $buffer_size"
make tests "BUFFER_SIZE=$buffer_size"
echo "Test compiled"

function test_input() {
	if [ "$quiet" = true ]; then
		./input_files ./input/$1 >/dev/null
		printf "%-30s\t" "Testing $1"
		if [ $? -ne 0 ]; then
			printf "\x1b[31mfailed\n\x1b[0m" $1
		else
			printf "\e[032m\u2713\e[0m\n"
		fi
	else
		./input_files ./input/$1
	fi
}

function leak_checks() {
	rm -f valgrind_output.txt
	count=0
	failed_count=0
	printf "\x1b[33m%-30s\t\x1b[0m\n" "Checking leaks"
	for i in ${inputs[@]}; do
		printf "%-30s\t" "Checking $i"
		count=$((count + 1))
		if [[ ! -f ./input/$i ]]; then
			printf "\x1b[31m\u2715\x1b[0m\n"
			printf "error: $i File not found\n"
			failed_count=$((failed_count + 1))
			continue
		fi
		/bin/valgrind --show-leak-kinds=all --leak-check=full \
			--track-origins=yes \
			--error-exitcode=1 \
			./input_files ./input/$i >/dev/null \
			2>>valgrind_output.txt
		if [ $? -eq 0 ]; then
			printf "\e[032m\u2713\e[0m\n"
		else
			printf "\x1b[31mFAIL\x1b[0m\n"
			failed_count=$((failed_count + 1))
		fi
	done
	printf "%-30s\t" "Checking not_allowed"
	count=$((count + 1))
	/bin/valgrind --show-leak-kinds=all --leak-check=full \
		--track-origins=yes \
		--error-exitcode=1 \
		./no_allowed >/dev/null \
		2>>valgrind_output.txt
	if [ $? -eq 0 ]; then
		printf "\e[032m\u2713\e[0m\n"
	else
		failed_count=$((failed_count + 1))
		printf "\x1b[31m\u2715\x1b[0m\n"
	fi
	printf "Leak check passed %-2d \n" $(($count - $failed_count))
	if [ $failed_count -eq 0 ]; then
		printf "\x1b[32mAll leak tests passed\x1b[0m\n"
	else
		printf "\x1b[31mLeak test failed %-2d\x1b[0m\n" $failed_count
		printf "\x1b[33m%-30s\t\x1b[0m\n" "Leak check done"
	fi
	return 0
}

if [ $# -ne 0 ]; then
	printf "test_input %s\n" $1
	test_input $1
	exit $?
fi

test_input test1.txt
test_input test2.txt
test_input test3.txt
test_input test4.txt
test_input no_newline.txt
leak_checks
