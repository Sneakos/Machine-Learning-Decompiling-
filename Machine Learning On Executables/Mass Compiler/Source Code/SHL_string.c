#include <stdio.h>
#include <string.h>

char  *SHLPassword(char *password, char *unobs);

int main() {
	char password[13] = { 146, 216, 222, 236, 202, 224, 234, 224, 224, 210, 202, 230, 0 };
    char input[500];
	char unobs[14] = { 0 };
    int same = -1;

    while (1) {
        printf("Please enter the password: ");
        scanf("%s", input);

		SHLPassword(password, unobs);
        same = strcmp(unobs, input);

        if (same == 0) {
            printf("You got it!\n");
			system("pause");

            return 0;
        }
    }
}

char *SHLPassword(char *password, char *unobs) {

	for (int i = 0; i < 12; i++) {
		unobs[i] = (password[i] & 0xFF) >> 1;
	}

	return;
}