#include <stdlib.h>
#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - function that sorts an array using
 * the selection sort method
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i, min = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
