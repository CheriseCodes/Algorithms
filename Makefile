# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

CC = clang++
OPTIONS = -std=c++20 -stdlib=libc++ -Wall -g

order_statistics: main.cc order_statistics.cc sorting.cc algoutils.cc
	@echo "Checking.."
	$(CC) $(OPTIONS) -v -o main main.cc order_statistics.cc sorting.cc algoutils.cc
stack: main.cc stack.h
	@echo "Checking.."
	$(CC) $(OPTIONS) -v -o main main.cc

queue: main.cc queue.h
	@echo "Checking.."
	$(CC) $(OPTIONS) -v -o main main.cc

clean:
	@echo "Cleaning up..."
	rm -rvf sorting.o main.o main