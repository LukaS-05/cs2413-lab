#include "Student.h"
#include <stdio.h>

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void sort_arr(int* arr, int arr_size);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

 // TODO: implement

    printf("%d", nums2Size);
    for (int i = 0; i < n; i++)
    {
        *(nums1+m+i) = *(nums2+i);
    }
    sort_arr(nums1, nums1Size);

}


void sort_arr(int* arr, int arr_size)
{
    int* i = arr;
    int* j = arr;
    while (i-arr < arr_size-1)
    {
        if (j-arr < arr_size-1)
        {
            j++;
        }
        else
        {
            i++;
            j=i;
        }
        if (*i > *j)
        {
            int temp = *j;
            *j = *i;
            *i = temp;
        }
    }
}