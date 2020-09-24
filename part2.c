#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

uint64_t hexchar2val(char in[])
{
    int i=0, in_len = strlen(in) ;
    uint64_t result=0 ;
    
    if(in_len>2 && in[0]=='0' && in[1]=='x') i = 2 ;

    for( ; i < in_len ; i++)
    {
        const uint8_t letter = in[i] & 0x40;
	const uint8_t shift = (letter >> 3) | (letter >> 6);

	result = (result << 4) | ((in[i] + shift) & 0xf);
    }
    return result ;

}

int main()
{
    printf("%ld\n",hexchar2val("0x00BAB10C")) ;

    return 0 ;
}

