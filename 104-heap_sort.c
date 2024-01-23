#include "sort.h"

/**
 * switch_root - A function that swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @hight: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void switch_root(int *array, size_t root, size_t hight, size_t size)
{
	size_t low = 0, fifo = 0, tmp = 0;
	int auxi = 0;

	while ((low = (2 * root + 1)) <= hight)
	{
		tmp = root;
		fifo = low + 1;
		if (array[tmp] < array[low])
			tmp = low;
		if (fifo <= hight && array[tmp] < array[fifo])
			tmp = fifo;
		if (tmp == root)
			return;
		auxi = array[root];
		array[root] = array[tmp];
		array[tmp] = auxi;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - A function that sorts an array using heap algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t hight = 0, increment_gp = 0;
	int tmp = 0;

		if (array == NULL || size < 2)
			return;

		for (increment_gp = (size - 2) / 2; 1; increment_gp--)
		{
			switch_root(array, increment_gp, size - 1, size);
			if (increment_gp == 0)
				break;
		}

		hight = size - 1;
		while (hight > 0)
	{
		tmp = array[hight];
		array[hight] = array[0];
		array[0] = tmp;
		print_array(array, size);
		hight--;
		switch_root(array, 0, hight, size);
	}
}
