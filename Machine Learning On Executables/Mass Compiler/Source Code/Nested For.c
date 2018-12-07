#include <stdio.h>
#include <stdlib.h>

int main()
{
	int length = 5;
	int width = 7;

    for(length=5;length >=0;length--){
        for(width=7;width >=0;width--){
            printf("*");
        }
        width = 7;
        printf("\n");
    }

    return 0;
}
