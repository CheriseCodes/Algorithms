# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

CC = g++

all: main

main: main.o sorting.o
	@echo "Checking.."
	$(CC) -v -o main main.cc sorting.cc

sorting.o: sorting.cc
	@echo "Creating object sorting.o.."
	$(CC) -c sorting.cc

main.o: main.cc
	@echo "Creating object main.o.."
	$(CC) -c main.cc

clean:
	@echo "Cleaning up..."
	rm -rvf sorting.o main.o main