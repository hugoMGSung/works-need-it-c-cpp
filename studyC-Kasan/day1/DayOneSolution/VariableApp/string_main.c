// ���ڿ� �н� main.c
#define _CRT_SECURE_NO_WARNINGS  // strcpy, scanf�� ����� �� ��ó����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
	const double tax_rate = 0.12; // ���� �ʱ�ȭ ���ȭ
	char fruit[7] = "�޻��";
	// char main[8] = "test";
	int ia = 0;

	printf("%d\n", ia);

	strcpy(fruit, "apple");
	printf("%s\n", fruit);

	// tax_rate = 0.15;  // error ������� ����Ұ�
}