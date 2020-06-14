#include "sort.h"
/**
 * swap_arr - swap two numbers in the array
 * @a: number 1
 * @b: number 2
 * @array: array to print in case of swap
 * @size: array size
 * Return: Nothing
 */
void swap_arr(int *a, int *b, int *array, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	if (temp != *a)
		print_array(array, size);
}
/**
 * partition - function to parse the array in 2 arrays
 * @array: array
 * @low: position of first element of the array
 * @last: position of the last element
 * @size: array size
 * Return: final position of pivot
 */
int partition(int *array, int low, int last, size_t size)
{
	int pivot = array[last], j;
	int i = low - 1;

	for (j = low; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_arr(&array[j], &array[i], array, size);
		}
	}
	i = i + 1;
	swap_arr(&array[i], &array[last], array, size);
	return (i);

}
/**
 * new_quick - Recursive function to sort the array
 * @array: array
 * @low: position of first element of the array
 * @last: position of the last element
 * @size: array size
 * Return: Nothing
 */
void new_quick(int *array, int low, int last, size_t size)
{
	int div;

	if (low < last)
	{
		div = partition(array, low, last, size);
		new_quick(array, 0, div - 1, size);
		new_quick(array, div + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array in ascending order
 * @array: array to be sroted
 * @size: array size
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int last, low;

	last = size - 1;
	low = 0;
	if (array == NULL || size < 2)
		return;
	new_quick(array, low, last, size);
}
