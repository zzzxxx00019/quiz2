#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize)
{
    int low = 0, high1 = 0, high2 = 0 ;
    for(int i = 0 ; i < numsSize ; i++)
    {
        int h1 = high1, h2 = high2, lo = low ;

        low = ( ~h2 & ~h1 & ~lo & nums[i] )|( ~h2 & ~h1 & lo & ~nums[i] ) ;
        high1 = (~h2 & ~h1 & lo & nums[i] )|( ~h2 & h1 & ~lo & ~nums[i] ) ;
        high2 = (~h2 & h1 & ~lo & nums[i] )|(h2 & ~h1 & ~lo & ~nums[i] ) ;
    }

    return low ;
}

int main()
{
    int nums[] = {2, 2, 4, 2, 3, 2, 4, 4, 4} ;

    printf("result = %d\n", singleNumber(nums, 9)) ;

    return 0 ;
}
