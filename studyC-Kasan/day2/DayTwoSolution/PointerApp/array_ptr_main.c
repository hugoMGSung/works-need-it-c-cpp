#include <stdio.h>

//void print_array(int []); //����
void print_array(int*);

int main(void) {
	//int arr[3]; // ������ 3 �迭
	//
	//*(arr + 0) = 10;
	//*(arr + 1) = 20;
	//*(arr + 2) = 30;

	//for (int i = 0; i < 3; i++) {
	//	printf("%d\t", arr[i]);
	//}
	int ary[5] = { 10,20,30,40,50 };
	print_array(ary);
}

void print_array(int *a) { // (int a[]) ����
	for (int i = 0; i < 5; i++) {
		printf("%d\t", a[i]);
	}
}