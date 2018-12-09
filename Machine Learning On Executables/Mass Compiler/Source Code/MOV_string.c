#include <stdio.h>
#include <string.h>

char *MOVPassword(char *password, char *unobs);

int main() {
		char password[14] = "peIipleuospvs\0";
    char input[500];
		char unobs[14] = { 0 };
    int same = -1;

    while (1) {
        printf("Please enter the password: ");
        scanf("%s", input);

		MOVPassword(password, unobs);
        same = strcmp(unobs, input);

        if (same == 0) {
            printf("You got it!\n");
			system("pause");

            return 0;
        }

    }
}

char *MOVPassword(char *password, char *unobs) {
	int i = 0, j = 0;

	for (int i = 2; i < 39; i += 3) {
		unobs[j] = password[i % 13];
		j++;
	}

	return;
}
