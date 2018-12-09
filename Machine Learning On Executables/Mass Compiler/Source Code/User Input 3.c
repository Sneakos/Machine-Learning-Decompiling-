# include <stdio.h>

int main ()
{
	int value;

	printf ("Enter an integer value: ");
	scanf ("%d", &value);

	printf ("2 digits padding: %02d\n", value) ;
	printf ("3 digits padding: %03d\n", value) ;
	printf ("4 digits padding: %04d\n", value) ;

	return 0;
}