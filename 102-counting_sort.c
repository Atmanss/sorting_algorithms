#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, max_numb;
	int *counter = NULL, *naskh = NULL;
	size_t j, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	naskh = malloc(sizeof(int) * size);
	if (naskh == NULL)
		return;
	for (j = 0, max_numb = 0; j < size; j++)
	{
		naskh[j] = array[j];
		if (array[j] > max_numb)
			max_numb = array[j];
	}
	counter = malloc(sizeof(int) * (max_numb + 1));
	if (counter == NULL)
	{
		free(naskh);
		return;
	}
	for (i = 0; i <= max_numb; i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[array[j]] += 1;
	for (i = 0; i <= max_numb; i++)
	{
		temp = counter[i];
		counter[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[counter[naskh[j]]] = naskh[j];
		counter[naskh[j]] += 1;
	}
	print_array(counter, max_numb + 1);
	free(counter);
	free(naskh);
}
