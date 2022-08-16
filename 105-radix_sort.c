#include "sort.h"

int return_max(int arr[], int n)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

void countsort(int *array, int n, int place_val)
{
    int output[n];
    int i;
    int count[10] = {0};

    for (i = 0; i < n; i++)
        count[(array[i] / place_val) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / place_val) % 10] - 1] = array[i];
        count[(array[i] / place_val) % 10]--;
    }
    print_array(array, n);
}
void radix_sort(int *array, size_t size)
{
    int max_val = return_max(array, size);
    int place_val;

    for (place_val = 1; max_val / place_val > 0; place_val *= 10)
        countsort(array, size, place_val);
}