#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.

    int* i = nums;
    int* j = nums+n;

    while(i != j)
    {
        if (*i + *j < target)
        {
            i++;
        }
        else if (*i + *j > target)
        {
            j--;
        }
        else
        {
            *out_i = i - nums;
            *out_j = j - nums; 
            return 1;
        }
    }

    return 0;
}
// think about the time complexity and space complexity of your solution

