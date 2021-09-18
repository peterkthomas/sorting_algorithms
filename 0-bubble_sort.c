#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int j, temp, endloop = 0;

	if (!array || size < 2)
		return;

	while(!endloop)
	{
		endloop = 1;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				endloop = 0;
			}
		}
		size--;
	}
}
