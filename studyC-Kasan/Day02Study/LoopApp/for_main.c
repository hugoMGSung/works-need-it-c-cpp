/*
 * for_main.c
 * 작성일 : 2022-06-17
 */
#include <stdio.h>

/// <summary>
/// 메인엔트리 함수
/// </summary>
/// <param name=""></param>
/// <returns>0(정상)</returns>
int main(void) {
	double a = 1;
	
	for (int i = 0; i < 300; i++) { // (초기값; 반복조건; 증감연산)
		a = a * 2;
	}
	printf("a = %lld\n", a);
}