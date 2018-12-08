#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[10] = {2,4,6,8,9,7,5,3,1,0};

    int i = 10;
    int target = 3;
    int b = 0;

    printf("%d\n",i);
    while(i > 0){
        if(numbers[i] == target){
            b = 1;
        }
        i--;
    }

    printf("Is in list: %d\n", b);


    return 0;
}
