#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement

    *returnSize = digitsSize;
    int* i = digits+digitsSize-1;
    *i += 1;
    while (i-digits > 0)
    {
        if (*i == 10)
        {
            *i = 0;
            *(i-1) += 1;
            i--;
        }
        else
        {
            *returnSize = digitsSize;
            return digits;
        }
    }
    if (*digits == 10)
    {
        int* new_digits = (int*)calloc(digitsSize+1, sizeof(int));
        *new_digits = 1;
        *returnSize = digitsSize+1;
        return new_digits;
    }
    return digits;
}

