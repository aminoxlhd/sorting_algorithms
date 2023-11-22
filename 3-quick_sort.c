#include "sort.h"


/**
 * lomuto_qsort - Lomuto partition scheme.
 * @array: Array to be sorted.
 * @low: The lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array we want to sort.
 * Return: Index of the pivot element (int).
 */
int lomuto_qsort(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j, temp;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * quicksort - A recursive function that will quick sort the array.
 * @array: Array to be sorted.
 * @low: The lowest index of the array.
 * @high: The highest index of the array.
 * @size: the size of the array we want to sort.
 * Return: void.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_qsort(array, low, high, size);
		quicksort(array, low, partition_index - 1, size);
		quicksort(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort.
 * @array: the array we want to sort.
 * @size: the size of the array we want to sort.
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
