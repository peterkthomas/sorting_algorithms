#include "sort.h"

/**
 * array_split - splits an array
 * @array: array of data
 * @size: size of array
 * @left: left index
 * @right: right index
 */
int array_split(int *array, size_t size, int left, int right)
{
	int i, j, pivot, temp;

	pivot = array[right];
	i = left;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[j];
				array[j] = 	array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[right])
	{
		temp = array[i];
		array[i] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (i);
}
/**
 * array_sort - sorts data recursively
 * array: array of data
 * size: size of the array
 * @left: index of the left side of pivot
 * @right: index of the right side of pivot
 */
void array_sort(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = array_split(array, size, left, right);
		array_sort(array, size, left, pivot - 1);
		array_sort(array, size, pivot + 1, right);
	}
}
/**
 * quick_sort - implementation of a quick sort
 * @array: array of data
 * @size: array's size
 */
void quick_sort (int *array, size_t size)
{
	int left = 0, right = size - 1;

	if (!array || size < 2)
		return;

	array_sort (array, size, left, right);

}
