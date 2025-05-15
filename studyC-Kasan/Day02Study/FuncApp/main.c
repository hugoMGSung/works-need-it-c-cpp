#include <stdio.h>

// 함수정의
int sum(int, int);

// 메인함수
int main(void) {
	printf("합산하기\n");

	int total = sum(100, 34);
	printf("합계, %d\n", total);
}

// 함수구현
int sum(int x, int y) {
	int res;

	res = x + y;
	return res;
}