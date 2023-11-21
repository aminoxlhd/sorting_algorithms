#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending
* order using the Bubble sort algorithm.
* @array: array to sort
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;

	while (i < size)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	i++;
	}
}
