#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *baseMerge = NULL;

	if (array == NULL || size < 2)
		return;
	baseMerge = malloc(sizeof(int) * size);
	if (baseMerge == NULL)
		return;
	for (; i < size; i++)
		baseMerge[i] = array[i];
	combine_partition(0, size, array, baseMerge);
	free(baseMerge);
}

/**
 * merge - A function that sorts the subarrays.
 * @low: Lower index.
 * @fifo: Middle index.
 * @hight: Higher index.
 * @dst: Destination for data.
 * @sfm: Input data.
 * Return: Nothing
 */
void merge(size_t low, size_t fifo, size_t hight, int *dst, int *sfm)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(sfm + low, fifo - low);
	printf("[right]: ");
	print_array(sfm + fifo, hight - fifo);
	i = low;
	j = fifo;
	k = low;
		for (; k < hight; k++)
		{
			if (i < fifo && (j >= hight || sfm[i] <= sfm[j]))
			{
				dst[k] = sfm[i];
				i++;
			}
			else
			{
				dst[k] = sfm[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dst + low, hight - low);
}

/**
 * combine_partition - A funtion that splits the array recursively.
 * @low: Lower index.
 * @hight: Higher index.
 * @array: The array to sort.
 * @baseMerge: The naskh of the array.
 * Return: Nothing.
 */
void combine_partition(size_t low, size_t hight, int *array, int *baseMerge)
{
	size_t fifo = 0;

	if (hight - low < 2)
		return;
	fifo = (low + hight) / 2;
	combine_partition(low, fifo, array, baseMerge);
	combine_partition(fifo, hight, array, baseMerge);
	merge(low, fifo, hight, array, baseMerge);
	for (fifo = low; fifo < hight; fifo++)
		baseMerge[fifo] = array[fifo];
}
