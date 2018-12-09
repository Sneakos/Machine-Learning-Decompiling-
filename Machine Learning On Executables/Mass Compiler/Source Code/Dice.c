#include <stdio.h>
#include <stdlib.h>

int main(){
    int rolls,i;
    int count[7] = {0};
    srand(time(NULL));
    int r = 0;

    printf("How many times to roll:");
    scanf("%d",&rolls);
    rolls = rolls * 2;

    while(rolls > 0){
        r = rand()%6+1;
        count[r]++;
        rolls--;
    }

    for(i=1;i<=6;i++){
        printf("%d occurred %7d times.\n",i,count[i]);
    }
    return 0;
}
