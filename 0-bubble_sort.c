#include "sort.h"

/**
 * this code created by Mohamed & Atmane
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * Return: None.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int auxi = 0;

	if (array == NULL || size == 0)
		return;
	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				auxi = array[j + 1];
				array[j + 1] = array[j];
				array[j] = auxi;
				print_array(array, size);
			}
		}
	}
}
