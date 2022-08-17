#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define mysqlip "127.0.0.1"
#define port 33306
#define loginusername "bms"
#define loginpassword "1234"
#define mysqlname "bms"

int main() {
	MYSQL* conn;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;

	unsigned int num_fields;
	unsigned long* lengths;

	int i = 0;

	setlocale(LC_ALL, "Korean");
	conn = mysql_init(NULL);
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "�������! : %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}

	printf("���Ἲ��!\n");
	printf("�������� %s\n", conn->server_version);

	query_stat = mysql_query(conn, "SELECT * FROM books_info");
	if (query_stat != 0) {
		fprintf(stderr, "��������! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return EXIT_FAILURE;
	}

	result = mysql_store_result(conn);
	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	mysql_close(conn);
	printf("��������\n");
	system("pause");
	return EXIT_SUCCESS;
}