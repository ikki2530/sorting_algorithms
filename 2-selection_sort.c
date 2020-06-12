#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

void selection_sort(int *array, size_t size)
{
        size_t i, j;
        int temp;

        for (i = 0; i < size - 1; i++)
        {
                for (j = i + 1; j < size; j++)
                {
                        if (array[i] > array[j])
                        {
                                if (array[i] != array[j])
                                {
                                        temp = array[i];
                                        array[i] = array[j];
                                        array[j] = temp;
                                }
                        }
                }
                print_array(array, size);
        }
}