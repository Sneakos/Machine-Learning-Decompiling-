#include <stdio.h>
#include <stdlib.h>

int main()
{
	int length = 5;
	int width = 7;
    while(length >= 0){
    	while(width >= 0){
    		printf("*");
    		width = width - 1;
    	}
    	width = 7;
    	printf("\n");
    	length = length - 1;
    }

    return 0;
}
