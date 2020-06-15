#include "sort.h"

/**
 * shell_sort - sort using shell knuth secuence
 * @array: input array that will be sorted
 * @size: input size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 0, o, v, i;

	if (size < 2)
		return;

	while (n <= (size / 3))
		n = ((n * 3) + 1);
	while (n >= 1)
	{
		for (i = n; i < size; i++)
			for (o = i; o >= n && array[o] < array[o - n]; o -= n)
			{
				if (array[o] != array[o - n])
				{
					v = array[o];
					array[o] = array[o - n];
					array[o - n] = v;
				}
			}
		n /= 3;
		print_array(array, size);
	}
}
