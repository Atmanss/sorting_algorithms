#include "sort.h"
#include <stdio.h>

/**
 * comparing_bitonic - sort the values in a sub-array with respect to
 * the Bitonic sort algorithm
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 *
 * Return: void
 */
void comparing_bitonic(char up, int *array, size_t size)
{
	size_t i, envo;
	int swap;

	envo = size / 2;
	for (i = 0; i < envo; i++)
	{
		if ((array[i] > array[i + envo]) == up)
		{
			swap = array[i];
			array[i] = array[i + envo];
			array[i + envo] = swap;
		}
	}
}

/**
 * merging_bitonic - recursive function that merges two sub-arrays
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 *
 * Return: void
 */
void merging_bitonic(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	comparing_bitonic(up, array, size);
	merging_bitonic(up, array, size / 2);
	merging_bitonic(up, array + (size / 2), size / 2);
}

/**
 * bitonic_sorting - recursive function using the Bitonic sort algorithm
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 * @t: total size of the original array
 *
 * Return: void
 */
void bitonic_sorting(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bitonic_sorting(1, array, size / 2, t);
	bitonic_sorting(0, array + (size / 2), size / 2, t);
	merging_bitonic(up, array, size);
	printf("natija [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sorting(1, array, size, size);
}
