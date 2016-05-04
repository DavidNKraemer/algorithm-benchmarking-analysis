CC=gcc -std=gnu99
FLAGS= -Wall -Wextra
L= -lm
DEPENDENCIES= binary_search_recursive.c binary_search_iterative.c linear_search_recursive.c linear_search_iterative.c ../utils/reader.c

searchlib: searchlib.h binary_search_recursive.c binary_search_iterative.c linear_search_recursive.c linear_search_iterative.c
	clear &&\
	$(CC) $(FLAGS) $(L) -c binary_search_recursive.c && \
	$(CC) $(FLAGS) $(L) -c binary_search_iterative.c && \
	$(CC) $(FLAGS) $(L) -c linear_search_recursive.c && \
	$(CC) $(FLAGS) $(L) -c linear_search_iterative.c

main: searchlib.h binary_search_recursive.c binary_search_iterative.c linear_search_recursive.c linear_search_iterative.c ../utils/reader.c
	clear && \
	$(CC) $(FLAGS) $(L) -o main.o main.c $(DEPENDENCIES)

