#include <stdio.h>
#include <stdlib.h>
// 한줄 주석
/* 여러줄 주석
 *  두번째 줄을 만들면 알아서 * 붙습니다.
 *  이 줄은 컴파일에 아무런 영향을 주지 않습니다.
 * main.c
 * 작성일 : 2022년 6월 16일 11:28 
 * 작성자 : 성명건 
 * 내용 : 기본적인 C 학습 코드
 */

int main(void) {
	//10 + 20;	// 10과 20을 더한다
	printf("%d\n", 10 + 20);
	printf("Hello World");
	system("pause");
		
	return 0;	// 프로그램을 정상적으로 종료한다
}