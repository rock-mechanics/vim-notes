# the program make will try to find a file called Makefile in the directory
#
# all : clean speicify the all block is depend on the clean block.
# so it will run make clean first.
# then it will run make all
# -g flag allows the debug program to track the code address
all: clean
	clang -Wall -g ex07.c -o ex07
clean:
	rm -rf ex07
