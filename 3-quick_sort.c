#include "sort.h"
void swap_arr(int *a, int *b, int *array, size_t size)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
        if (temp != *a)
                print_array(array, size);
}
int partition(int *array, int low, int last, size_t size)
{
        int pivot = array[last], j;
        int i = low - 1;

        /*printf("last %d\n", array[last]);*/
        for (j = low; j < last; j++)
        {
                /*printf("array[%d] = %d, pivot = %d\n", j, array[j], pivot);*/
                if (array[j] <= pivot)
                {
                        /*printf("inside if\n");*/
                        i++;
                        swap_arr(&array[j], &array[i], array, size);
                        /*print_array(array, size);*/
                }
        }
        i = i + 1;
        swap_arr(&array[i], &array[last], array, size);
        /*printf("Last print of partition\n");*/
        /*print_array(array,size);*/
        return (i);

}

void new_quick(int *array, int low, int last, size_t size)
{
        int div;

        if (low < last)
        {
                div = partition(array, low, last, size);
                /*printf("low: %d, last= %d, div, %u, size: %lu\n\n", low, last, div, size);*/

                new_quick(array, 0, div-1, size); /*left array*/
                new_quick(array, div+1, last, size); /*right*/
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

        new_quick(array, low, last, size);
}