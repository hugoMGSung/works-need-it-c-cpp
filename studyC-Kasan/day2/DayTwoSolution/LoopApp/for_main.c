/*
 * for_main.c
 * �ۼ��� : 2022-06-17
 */
#include <stdio.h>

/// <summary>
/// ���ο�Ʈ�� �Լ�
/// </summary>
/// <param name=""></param>
/// <returns>0(����)</returns>
int main(void) {
	double a = 1;
	
	for (int i = 0; i < 300; i++) { // (�ʱⰪ; �ݺ�����; ��������)
		a = a * 2;
	}
	printf("a = %lld\n", a);
}