#include <stdio.h>
#include <stdlib.h>

int main(void) {	
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int)); // 4����Ʈ�� �޸𸮸� ���� �Ҵ�
	if (pi == NULL) {
		printf("# �޸𸮰� �����մϴ�.\n");
		exit(1); // ������������ ����
	}

	pd = (double*)malloc(sizeof(double));
	if (pd == NULL) {
		printf("# �޸𸮰� �����մϴ�.\n");
		exit(1); // ������������ ����
	}

	*pi = 10;
	*pd = 3.141592;
	printf("%d\n", *pi);
	printf("%lf\n", *pd);
	
	free(pi); free(pd);  // �޸� ����! ����õɶ����� ����

}