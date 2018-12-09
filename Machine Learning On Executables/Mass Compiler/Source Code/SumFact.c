#include <stdio.h>
#include <stdlib.h>

int factorial(int num){
        int f = 1;
        while(num > 0){
                f = f * num;
                num--;
        }
        return f;
}

int summation(int num){
        int s = 0;
        while(num > 0){
                s = s + num;
                num--;
        }
        return s;
}

int main(){
        int input;

        printf("Enter number for summation and factorial(0 to exit):");
        scanf("%d",&input);

        while (input >=1){
                printf("Factorial:%d\n",factorial(input));
                printf("Summation:%d\n",summation(input));

                printf("Enter number for summation and factorial(0 to exit):");
                scanf("%d",&input);
        }
        return 0;
}
