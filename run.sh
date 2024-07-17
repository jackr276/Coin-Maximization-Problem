# Author: Jack Robbins
#!/bin/bash

# Simple runner script for c programs

if [[ ! -d out ]]; then
	mkdir out
fi

#Clean out the out dir
rm -r out/*

if [[ ! -f ./src/coin_problem.c ]]; then
	echo "coin_problem.c does not exist"
	exit 1
fi

# go heavy on the warnings
gcc -Wall -Wextra ./src/coin_problem.c -o ./out/coin_problem

./out/coin_problem






