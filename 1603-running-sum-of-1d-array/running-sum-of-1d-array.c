/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//#include <stdio.h>
//#include <stdlib.h>
int* runningSum(int* nums, int numsSize, int* returnSize) {
    
    // 1. Set the size
    *returnSize = numsSize;
    // 2. Allocate memory
    int* result = (int*)malloc(numsSize * sizeof(int));

    // 2a. (Refinement) Check if allocation failed
    if (result == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    // 3. Handle the base case
    result[0] = nums[0];
    // 4. Iterate with the while loop
    int i = 1;

    while (i < numsSize)
    {
        result[i] = result[i-1] + nums[i];
        i++;
    }
    // 5. Return the pointer
    return result;
}

/* ---------------------------------------------- */
/*
int main()
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = runningSum(nums, numsSize, &returnSize);

    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }
    printf("Result: [");
    int i = 0;

    while (i < returnSize)
    {
        printf("%d", result[i]);
        if (i < returnSize - 1)
        {
            printf(", ");
        }
        i++;
    }
    printf("]\n");
    free(result);
    return 0;
}
*/