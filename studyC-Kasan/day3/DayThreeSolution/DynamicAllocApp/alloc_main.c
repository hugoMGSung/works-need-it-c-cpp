#define _CRT_SECURE_NO_WARNINGS
// �迭 �����Ҵ�
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi;
	int i = 0, sum = 0;

	// �ٽ�! �����Ҵ�
	pi = (int*)malloc(3 * sizeof(int));  // 20����Ʈ 
	if (pi == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1); // �Ϲ��� ����
	}

	for (i = 0; i < 3; i++) {
		printf("%d\t", pi[i]); // �迭���·� �Է�		
	}
	printf("\n");

	printf("������ ���̸� �Է��ϼ��� > ");
	for (i = 0; i < 3; i++) {
		scanf("%d", (pi + i)); // == &pi[i]
		sum += *(pi + i); // == pi[i]
	}

	printf("������ ��ճ��� : %.1lf\n", sum / 3.0);
	free(pi); // �����޸� ����, �ʼ�(!)

	//exit(0);  // ���������� ���α׷� ���� �Ϲ��� ����
}