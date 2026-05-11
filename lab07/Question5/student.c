/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/

void swap(int arr[], int i, int j);
int smallest(int arr[], int i, int j);

void selectionSort(int arr[], int size) {
    // TODO: implement selection sort
    
    if (size < 2)
    {
        return;
    }

    int pos;
    for (int i = 0; i < size; i++)
    {
        pos = smallest(arr, i, size);
        swap(arr, i, pos);
    }
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int smallest(int arr[], int i, int size)
{
    int small = arr[i];
    int pos = i;
    for (int j = i+1; j < size; j++)
    {
        if (small > arr[j])
        {
            small = arr[j];
            pos = j;
        }
    }
    return pos;
}