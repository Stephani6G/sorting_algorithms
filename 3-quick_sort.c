#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int lower, int upper);
void lomuto_sort(int *array, size_t size, int lower, int upper);
void quick_sort(int *array, size_t size);

/**
 * swap - function that  swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - a function that order a subset of an array
 * of integers according tothe lomuto partition
 * scheme (last element as pivot)
 * @array: the  array to be sorted
 * @size: size of the array
 * @lower: starting index of the subset to sort
 * @upper: ending index of the subset to sort
 * Return: final partition index (success)
 */

int lomuto_partition(int *array, size_t size, int lower, int upper)
{
	int *pivot, start, end;

	pivot = array + upper;
	for (end = start = lower; start < upper; start++)
	{
		if (array[start] < *pivot)
		{
			if (end < start)
			{
				swap(array + start, array + end);
				print_array(array, size);
			}
			end++;
		}
	}

	if (array[end] > *pivot)
	{
		swap(array + end, pivot);
		print_array(array, size);
	}

	return (end);
}

/**
 * lomuto_sort - function that  implements the
 * quicksort algorithm through recursion
 * @array: array to be sorted
 * @size: size of the array
 * @lower: starting index of the subset to sort
 * @upper: ending index of the subset to sort
 */

void lomuto_sort(int *array, size_t size, int lower, int upper)
{
	int part;

	if (upper - lower > 0)
	{
		part = lomuto_partition(array, size, lower, upper);
		lomuto_sort(array, size, lower, part - 1);
		lomuto_sort(array, size, part + 1, upper);
	}
}

/**
 * quick_sort -function that sorts an array of integers
 * in ascending order using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
