#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <stdio.h>

int main() {
    SQLHANDLE env; //�̺�Ʈ �ڵ�
    SQLHANDLE con; //���� �ڵ�
    SQLRETURN res; //���� ������� ����

    if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env)) { //�̺�Ʈ �ڵ� ����
        if (SQL_SUCCESS == SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) { //�ڵ� ȯ�漳��
            if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, env, &con)) //���� �ڵ� ����
            {
                res = SQLDriverConnect(con, NULL,
                    (SQLCHAR*)"DRIVER={SQL Server};SERVER=localhost, 1433; DATABASE=bms; UID=sa; PWD=password;",
                    SQL_NTS, NULL, 1024, NULL, SQL_DRIVER_NOPROMPT); //���� ���� �Է�. (���� = 1, ���� = -1 ����)
                if (res == 1)
                    printf("������ �����߽��ϴ�\n");
                else
                    printf("������ �����߽��ϴ�\n");
            }
        }
    }
}