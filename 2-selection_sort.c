#include "sort.h"

/**
 * selection_sort - selection sorting an array in ascending algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	int i, j, temp, s, temp2, position, flag = 0;

	s = size;
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < s - 1; i++)
	{
		temp2 = array[i];
		for (j = i + 1; j < s; j++)
		{
			if (temp2 > array[j])
			{
				flag = 1;
				temp2 = array[j];
				position = j;
			}
		}
		if (flag == 1)
		{
			temp = array[i];
			array[i] = array[position];
			array[position] = temp;
			print_array(array, size);
			flag = 0;
		}
	}
}
