#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int a = 0; a < n; a++) {
		if ((a % 3 == 0) || (a % 5 == 0)) {
			sum += a;
		}
	}

	printf("%d\n", sum);
}