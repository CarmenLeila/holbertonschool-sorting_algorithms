#include "sort.h"
/**
 * swap - swaps two integers
 * @index_a: first integer
 * @index_b: second integer
 */
void swap(int *index_a, int *index_b)
{
	int temp = *index_a;
	*index_a = *index_b;
	*index_b = temp;
}

/**
 * lomuto_partition - lomuto partition scheme
 * @array: array to partition
 * @size: size of array
 * @left: left index
 * @right: right index
 * Return: index of partition
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int index_a = left, index_b;

	for (index_b = left; index_b < right; index_b++)
	{
		if (array[index_b] < pivot)
		{
			if (index_a != index_b)
			{
				swap(&array[index_a], &array[index_b]);
				print_array(array, size);
			}
			index_a++;
		}
	}
	if (array[index_a] > array[right])
	{
		swap(&array[index_a], &array[right]);
		print_array(array, size);
	}
	return (index_a);
}

/**
 * lomuto_sort - sort algorithm give by lomuto
 * @array: array to sort
 * @size: size of array
 * @left: left index
 * @right: right index
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

