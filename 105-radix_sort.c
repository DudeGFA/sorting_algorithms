#include "sort.h"

/**
 * return_max - returns max value in an array
 * 
 * @arr: array 
 * @n: size of array 
 * Return: int 
 */
int return_max(int arr[], int n)
{
    int max_val = arr[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

/**
 * countsort - sorts an array using
 * countsort algorithm
 * 
 * @array: array to be sorted 
 * @n: size of array
 * @place_val: place value sorting depends on
 * Returns: nothing
 */
void countsort(int *array, int n, int place_val)
{
    int *output = malloc(sizeof(int) * n);
    int i;
    int count[10] = {0};

    if (output == NULL)
    {
        exit (98);
    }
    for (i = 0; i < n; i++)
        count[(array[i] / place_val) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / place_val) % 10] - 1] = array[i];
        count[(array[i] / place_val) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
    free (output);
}
/**
 * radix_sort - sorts an array using radix
 * algorithm
 * 
 * @array: array to be sorted
 * @size: size of array
 * Returns: nothing
 */
void radix_sort(int *array, size_t size)
{
    int max_val = return_max(array, size);
    int place_val;

    if (array == NULL || size <= 1)
        return;
    for (place_val = 1; max_val / place_val > 0; place_val *= 10)
    {
        countsort(array, size, place_val);
        print_array(array, size);
    }
}