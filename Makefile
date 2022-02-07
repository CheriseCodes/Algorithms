# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

CC = clang++
OPTIONS = -std=c++20 -Wall

all: main

main: main.o sorting.o
	@echo "Checking.."
	$(CC) $(OPTIONS) -v -o main main.cc sorting.cc

sorting.o: sorting.cc
	@echo "Creating object sorting.o.."
	$(CC) $(OPTIONS) -c sorting.cc

main.o: main.cc
	@echo "Creating object main.o.."
	$(CC) $(OPTIONS) -c main.cc

clean:
	@echo "Cleaning up..."
	rm -rvf sorting.o main.o main