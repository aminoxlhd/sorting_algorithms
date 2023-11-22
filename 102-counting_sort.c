#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* get_max_value - get the max value of an array.
* @array: the array where we'll search the max.
* @size: the size of the array.
* Return: the maximum value of the array.
*/
int get_max_value(int *array, size_t size)
{
	int max_value = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return (max_value);
}
/*
* counting_sort -sorts an array of integers in ascending order
* @array: the array we want to sort.
* @size: the size of the array we want to sort.
*/
void counting_sort(int *array, size_t size)
{
	int max_value;
	int *count, *sorted;
	size_t i;

	if (!array  || size == 0)
		return;
	 max_value = get_max_value(array, size);

	count = malloc((max_value + 1) * sizeof(int));
	sorted = malloc(size * sizeof(int));

	for (i = 0; i <= (size_t)max_value; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max_value; i++)
		count[i] += count[i - 1];

	print_array(count, max_value + 1);

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	print_array(count, max_value + 1);

	free(count);
	free(sorted);
}
