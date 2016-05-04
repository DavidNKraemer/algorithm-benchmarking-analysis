CC=gcc -std=gnu99
FLAGS= -Wall -Wextra -g
L= -lm
DEPENDENCIES= merge_sort_recursive.c merge_sort_iterative.c insertion_sort_recursive.c insertion_sort_iterative.c ../utils/reader.c

sortlib: sortlib.h merge_sort_recursive.c merge_sort_iterative.c insertion_sort_recursive.c insertion_sort_iterative.c
	$(CC) $(FLAGS) $(L) -c merge_sort_recursive.c && \
	$(CC) $(FLAGS) $(L) -c merge_sort_iterative.c && \
	$(CC) $(FLAGS) $(L) -c insertion_sort_recursive.c && \
	$(CC) $(FLAGS) $(L) -c insertion_sort_iterative.c

main: sortlib.h merge_sort_recursive.c merge_sort_iterative.c insertion_sort_recursive.c insertion_sort_iterative.c ../utils/reader.c
	$(CC) $(FLAGS) $(L) -o main.o main.c $(DEPENDENCIES)

