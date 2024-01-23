#include "sort.h"
/**
 * arr_swap - swap two numbers.
 * @a: integer
 * @b: integer
 **/

void arr_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lor_insertion -swap two nodes right left position
 * @array: array
 * @increment_gp: increment_gp
 * @currunt_index: actual position in the array
 **/
void lor_insertion(int *array, int increment_gp, int currunt_index)
{
	int i;

	for (i = currunt_index - increment_gp; i >= 0; i -= increment_gp, currunt_index -= increment_gp)
	{
		if (array[i] > array[currunt_index])
			arr_swap(&array[i], &array[currunt_index]);
		else
			break;
	}
}
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int increment_gp = 1, i, j;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (increment_gp < size / 3)
		increment_gp = increment_gp * 3 + 1;

	while (increment_gp > 0)
	{
		for (i = 0, j = increment_gp; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				arr_swap(&array[i], &array[j]);
				lor_insertion(array, increment_gp, i);
			}
		}
		print_array(array, size);
		increment_gp /= 3;
	}
}
