#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - finds the partition for the quicksort using the Hoare scheme
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @hight: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t hight, size_t size)
{
	int swap, pivot;

	pivot = array[hight];
	while (low <= hight)
	{
		while (array[low] < pivot)
			low++;
		while (array[hight] > pivot)
			hight--;
		if (low <= hight)
		{
			if (low != hight)
			{
				swap = array[low];
				array[low] = array[hight];
				array[hight] = swap;
				print_array(array, size);
			}
			low++;
			hight--;
		}
	}
	return (hight);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @hight: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t hight, size_t size)
{
	ssize_t pivot;

	if (low < hight)
	{
		pivot = partition(array, low, hight, size);
		quicksort(array, low, pivot, size);
		quicksort(array, pivot + 1, hight, size);

	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
