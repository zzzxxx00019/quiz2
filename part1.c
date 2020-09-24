#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while ((i + 8) <= size) {
        uint64_t payload;
        memcpy(&payload, str + i, 8);

	uint64_t A = payload + PACKED_BYTE(128 - 'A') ;
	uint64_t Z = payload + PACKED_BYTE(128 - 'Z' - 1) ;
	uint64_t a = payload + PACKED_BYTE(128 - 'a') ;
	uint64_t z = payload + PACKED_BYTE(128 - 'z' - 1) ;

	if( (A^Z) & PACKED_BYTE(0x80) || (a^z) & PACKED_BYTE(0x80))
	    return true ;

        i += 8;
    }
    while (i < size) {
	char tmp_c = str[i] ;
        if(tmp_c > 'Z')    tmp_c^=' ';
	    
	if(tmp_c >= 'A' && tmp_c <= 'Z') 
            return true;
        i++;
    }
    return false;
}

int main()
{
    char test[10]="0123456789" ;
    printf("test string is '%s'\n",test) ;

    if(is_ascii(test,strlen(test )))
	printf("True\n") ;

    else
	printf("false\n") ;

	
    return 0 ;
}
