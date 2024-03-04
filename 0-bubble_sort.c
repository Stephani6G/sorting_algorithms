#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - func that implements the bubble sor
 * for algorithms
 *
 * @array: an  array of integers
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
