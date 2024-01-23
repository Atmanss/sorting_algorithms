#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_srt(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @low: lower
 * @hight: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int low, int hight, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[hight], auxi = 0;

	for (; j < hight; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				auxi = array[i];
				array[i] = array[j];
				array[j] = auxi;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hight])
	{
		auxi = array[i + 1];
		array[i + 1] = array[hight];
		array[hight] = auxi;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_srt - quick sort
 * @array: given array
 * @low: lower
 * @hight:higher
 * @size: array's size
 * Return: void
 */
void quick_srt(int *array, int low, int hight, size_t size)
{
	int pivot;

	if (low < hight)
	{
		pivot = partition(array, low, hight, size);
		quick_srt(array, low, pivot - 1, size);
		quick_srt(array, pivot + 1, hight, size);
	}
}
