#include "sort.h"

/*
* shell_sort - a function that sorts an array of integers in ascending order 
* using the Shell sort algorithm, using a custom sequence
* @array: the array we want to sort.
* @size: the size of the array we want to sort.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t outer, inner;
	int current_value;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
        outer = gap;
		while (outer < size)
		{
			current_value = array[outer];
			inner = outer;

			while (inner >= gap && array[inner - gap] > current_value)
			{
				array[inner] = array[inner - gap];
				inner -= gap;
			}

			array[inner] = current_value;
            outer++;
		}

		gap = (gap - 1) / 2;
		print_array(array, size);
	}
}
