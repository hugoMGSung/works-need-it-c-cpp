#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int res = 1;
	int i = 1;
	while (i < 10) {
		if (i == 5) break;
		
		res = res * i;
		i++;
	}

	printf("%d\n", res);
}