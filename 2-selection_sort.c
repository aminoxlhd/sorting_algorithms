#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int temp, *min;
	size_t i, j;

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = &array[j];
		}
		if (array + i != min)
		{
			temp = *(array + i);
			*(array + i) = *min;
			*min = temp;
			print_array(array, size);
		}
	}
}
