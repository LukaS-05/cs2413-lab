#include <stdlib.h>

/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/

void mergeSortHelper(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    if (size > 1)
    {
        mergeSortHelper(arr, 0, size-1);
        return;
    }
    //(void)arr;
    //(void)size;
}

void mergeSortHelper(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right)/2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}

void merge(int arr[], int left, int mid, int right)
{
    int i = left; 
    int j = mid+1; 
    int k = 0;
    int* temp = malloc(sizeof(int) * (right - left + 1));

    while ((i <= mid) && (j<=right))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i += 1;
        }
        else
        {
            temp[k] = arr[j];
            j += 1;
        }
        k += 1;
    }

    if (j > right)
    {
        while (i <= mid)
        {
            temp[k] = arr[i];
            k += 1;
            i += 1;
        }
    }
    else
    {
        while (j <= right)
        {
            temp[k] = arr[j];
            k += 1;
            j += 1;
        }
    }

    for (int r = 0; r < k; r++)
    {
        arr[left + r] = temp[r];
    }

    free(temp);
}