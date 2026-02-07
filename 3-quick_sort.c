#include "sort.h"

static void quick_sort_rec(int *array, size_t size, int low, int high);
static int lomuto_partition(int *array, size_t size, int low, int high);
static void swap_ints(int *a, int *b);

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition)
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, size, 0, (int)size - 1);
}

/**
 * quick_sort_rec - Recursive quick sort helper
 * @array: Pointer to the array
 * @size: Size of the array (for printing)
 * @low: Starting index
 * @high: Ending index
 */
static void quick_sort_rec(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, size, low, high);
		quick_sort_rec(array, size, low, p - 1);
		quick_sort_rec(array, size, p + 1, high);
	}
}

/**
 * lomuto_partition - Partitions array using Lomuto scheme
 *                    Pivot is always the last element
 * @array: Pointer to the array
 * @size: Size of the array (for printing)
 * @low: Starting index
 * @high: Ending index (pivot index)
 *
 * Return: Final pivot position
 */
static int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * swap_ints - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

