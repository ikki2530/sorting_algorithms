#include "sort.h"

/**
 * bubble_sort - Sorting an array in ascending algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int flag = 1, tmp;
	unsigned int i = 0;

	if (array == NULL || size < 2)
		return;
	while (flag == 1)
	{
		flag = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
