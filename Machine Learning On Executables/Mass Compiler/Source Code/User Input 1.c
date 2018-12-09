# include <stdio.h>

int main ()
{
	int ivalue;
	float fvalue;
	char cvalue;

	//input 
	printf("Input integer, float and character values: ");
	scanf ("%d%f%*c%c", &ivalue, &fvalue, &cvalue);

	//print 
	printf ("Integer value: %d\n", ivalue) ;
	printf ("Float value: %f\n", fvalue) ;
	printf ("Character value: %c\n", cvalue) ;

	return 0;
}