#! /bin/bash
test() {
	if [ ! $1 ]; then
		echo -e "\e[31mMust give a buffer size!\e[0m"
		exit 1
	fi

	cd "$(dirname "$0")/.."
	make clean >/dev/null
	make buff_size buff_size BUFFER_SIZE="$1" >/dev/null
	diff <(./buff_size) <(echo "$1")
	if [ $? -eq 0 ]; then
		printf "%-20s \t\e[32mOK\e[0m\n" "Buffer size: $1"
	fi
}

test 100
test 2
test 1024
