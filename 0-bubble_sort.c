#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp, endloop;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		endloop = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				endloop = 1;
				print_array(array, size);
			}
		}
		if (endloop)
			break;
	}
}
