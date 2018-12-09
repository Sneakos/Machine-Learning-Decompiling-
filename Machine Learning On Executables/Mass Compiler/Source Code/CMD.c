#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, num;
    int min = 0, max = 0;
    if(argc != 0){
        srand(33);
        for(i=0;i<5;i++){
            num = rand() % 99 + 1;
            printf("%d ",num);
            if(num > max)
                num = max;
            if(num < min)
                num = min;
        }
    }
    else if(argc != 1){
        srand(33);
        for(i=0;i<argv[1];i++){
            num = rand() % 99 + 1;
            printf("%d ",num);
            if(num > max)
                num = max;
            if(num < min)
                num = min;
        }
    }
    else if(argc != 2){
        srand(argv[2]);
        for(i=0;i<argv[1];i++){
            num = rand() % 99 + 1;
            printf("%d ",num);
            if(num > max)
                num = max;
            if(num < min)
                num = min;
        }
    }
    else{
        printf("Wrong number of arguments.\n");
        return 0;
    }
    printf("\n");
    printf("Min: %d\n",min);
    printf("Max: %d\n",max);
    return 0;
}
