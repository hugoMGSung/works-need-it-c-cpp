#include <stdio.h>
#include <string.h>

int main(void) {
	char str[80];

	//str = "apple";
	strcpy(str, "apple");
	printf("%s\n", str);

	//str = "�ȳ��ϼ���~";
	strcpy(str, "�ȳ��ϼ���~");
	printf("%s\n", str);

	/*printf("�̸��� �Է��ϼ��� > ");
	gets(str);
	printf("�̸��� %s\n", str);*/

	// ���ڿ��� ���ϴ� ���̸�ŭ �߶� ������
	// substring�� ���� �����ʿ�
	char str2[20] = "mango tree";
	strncpy(str2, "apple-pie", 5); // 5�� 6���� �׽�Ʈ
	printf("%s\n", str2);

	// ���忭 ���� �Լ�
	char str3[80] = "straw"; // ����
	strcat(str3, "berry");
	printf("%s\n", str3);
	strncat(str3, "piece", 3); 
	printf("%s\n", str3);

	// ���ڿ� ���̸��� �Լ�
	printf("%d\n", strlen(str3));

	// ���ڿ� �� �Լ�
	char str5[80] = "pear"; // 112, 101, 97, 114
	char str6[80] = "peach"; // 112, 101, 97, 99, 104

	printf("������ ���߿� ������ �����̸� > ");
	if (strcmp(str5, str6, 3) > 0)
		printf("%s\n", str5);
	else
		printf("%s\n", str6);	
}