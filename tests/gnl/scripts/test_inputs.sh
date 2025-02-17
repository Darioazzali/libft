#! /bin/bash
test() {
	if [ ! $1 ]; then
		echo -e "\e[31mMust give a buffer size!\e[0m"
		exit 1
	fi

	make -C .. clean >/dev/null
	make -C .. input_files BUFFER_SIZE="$1" >/dev/null
	../input_files $2 >/dev/null
	printf "Testing file $2\t"
	if [ $? -eq 0 ]; then
		printf "%-20s \t\e[32mOK\e[0m\n" "Buffer size: $1"
	fi
}

test 100 ../input/test1.txt
test 2 ../input/test1.txt
test 1024 ../input/test1.txt
