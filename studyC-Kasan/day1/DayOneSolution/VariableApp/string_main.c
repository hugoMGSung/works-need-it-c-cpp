// 문자열 학습 main.c
#define _CRT_SECURE_NO_WARNINGS  // strcpy, scanf등 사용할 때 전처리기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
	const double tax_rate = 0.12; // 세율 초기화 상수화
	char fruit[7] = "햇사과";
	// char main[8] = "test";
	int ia = 0;

	printf("%d\n", ia);

	strcpy(fruit, "apple");
	printf("%s\n", fruit);

	// tax_rate = 0.15;  // error 상수값은 변경불가
}