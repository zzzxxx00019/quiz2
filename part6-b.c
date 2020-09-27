#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize)
{
    int lower = 0, higher = 0 ;
    for(int i = 0 ; i < numsSize ; i++)
    {
        lower = (~higher)&(lower^nums[i]) ;
        higher = (~lower)&(higher^nums[i]) ;
    }

    return lower ;
}


int main()
{
    int nums[] = {2, 2, 3, 2} ;

    printf("result = %d\n", singleNumber(nums, 4)) ;

    return 0 ;
}
