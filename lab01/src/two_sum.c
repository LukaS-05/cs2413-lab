#include "two_sum.h"
#include <stdio.h>

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {

    // TODO: implement Two Sum.
    // Requirements:
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0
<<<<<<< HEAD
    if (n < 2)
    {
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                *out_i = j;
                *out_j = i;
                return 1;
            }
        }
    }
=======
    // //////
>>>>>>> 4c8507e0bad4b6ecb925b00846d1e1cea0e8d9c3
    return 0;
}

//think about the time complexity and space complexity of your solution
