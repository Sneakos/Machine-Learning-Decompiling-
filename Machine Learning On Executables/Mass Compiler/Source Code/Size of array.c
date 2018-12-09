#include <stdio.h>
#include <string.h>
 
int main() {
    char array[4];
    memset(array, 0x42, sizeof(array));
 
    printf("Value of 1[array] = %#x\nValue of array[1] = %#x\n", 1[array], array[1]);
    /*
    Outputs:
    Value of 1[array] = 0x42
    Value of array[1] = 0x42
    */
    return 0;
}