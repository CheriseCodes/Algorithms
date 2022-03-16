# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

CC = clang++
OPTIONS = -std=c++20 -stdlib=libc++ -Wall -g

all: main

main: main.cc order_statistics.cc sorting.cc algoutils.cc
	@echo "Checking.."
	$(CC) $(OPTIONS) -v -o main main.cc order_statistics.cc sorting.cc algoutils.cc

clean:
	@echo "Cleaning up..."
	rm -rvf sorting.o main.o main