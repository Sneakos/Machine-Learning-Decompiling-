#include <stdio.h>

int main(void) 
{
	unsigned int value;

	//input "123afc"
	printf("Enter hexadecimal value without \"0x\": ");
	//using %x (small x)
	scanf("%x", &value);
	printf("value = 0x%x or 0X%X\n", value, value);

	//input "123AfC"
	printf("Enter hexadecimal value without \"0X\": ");
	//using X (capital x)
	scanf("%X", &value);
	printf("value = 0x%x or 0X%X\n", value, value);

	return 0;
}