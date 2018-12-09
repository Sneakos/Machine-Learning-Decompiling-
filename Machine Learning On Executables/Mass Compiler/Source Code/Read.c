#include <stdio.h>

int main()
{
        FILE *infp; //input file pointer
        int num1, num2;

        infp = fopen( "myin.dat", "r" );// opens a file for

        fscanf(infp, "%d", &num1 );// file scanf
        printf("First number from file: %d\n", num1);

        fscanf(infp, "%d", &num1 );
        printf("Second number from file: %d\n", num1);

        return 0;
}

