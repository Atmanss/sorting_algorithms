#ifndef __SORT__
#define __SORT__
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*print functions*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*sorting algorithms*/

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int low, int hight, size_t size);
void quick_srt(int *array, int low, int hight, size_t size);
void merge(size_t low, size_t fifo, size_t hight, int *dst, int *sfm);
void combine_partition(size_t low, size_t hight, int *array, int *baseMerge);
void switch_root(int *array, size_t root, size_t hight, size_t size);

#endif /* __SORT__ */
