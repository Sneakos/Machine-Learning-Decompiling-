#include <stdio.h>
#include <string.h>

char *XORPassword(char *password, char *unobs);

int main() {
    char password[13] = { 198, 227, 224, 249, 234, 255, 250, 255, 255, 230, 234, 252, 0 };
    char input[500];
	char unobs[14] = { 0 };
    int same = -1;

    while (1) {
        printf("Please enter the password: ");
        scanf("%s", input);

		XORPassword(password, unobs);
        same = strcmp(unobs, input);

        if (same == 0) {
            printf("You got it!\n");
			system("pause");
            
            return 0;
        }
    }
}

char *XORPassword(char *password, char *unobs) {
	
	for (int i = 0; i < 12; i++) {
		unobs[i] = password[i] ^ 143;
	}

	return;
}