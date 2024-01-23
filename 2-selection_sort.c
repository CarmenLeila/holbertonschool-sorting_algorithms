#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
			min = b;
		}

		if (min != a)
		{
			temp = array[a];
			array[a] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
