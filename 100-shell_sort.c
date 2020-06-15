#include "sort.h"

void shell_sort(int *array, size_t size)
{
        int gab = 1, i, j, s = size, temp;

        if (array == NULL || size < 2)
                return;

        while (gab < s / 3)
        {
                gab = gab * 3 + 1;
        }
        while (gab > 0)
        {
                for (i = gab; i < s; i++)
                {
                        temp = array[i];
                        for (j = i; j >= gab && array[j - gab] > temp; j -= gab)
                                array[j] = array[j - gab];
                        array[j] = temp;
                }
                gab = (gab - 1) / 3;
                print_array(array, size);
        }
}