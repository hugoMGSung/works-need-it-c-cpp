#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <stdio.h>

int main() {
    SQLHANDLE env; //이벤트 핸들
    SQLHANDLE con; //접속 핸들
    SQLRETURN res; //접속 결과저장 변수

    if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env)) { //이벤트 핸들 생성
        if (SQL_SUCCESS == SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) { //핸들 환경설정
            if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, env, &con)) //접속 핸들 생성
            {
                res = SQLDriverConnect(con, NULL,
                    (SQLCHAR*)"DRIVER={SQL Server};SERVER=localhost, 1433; DATABASE=bms; UID=sa; PWD=password;",
                    SQL_NTS, NULL, 1024, NULL, SQL_DRIVER_NOPROMPT); //접속 조건 입력. (성공 = 1, 실패 = -1 리턴)
                if (res == 1)
                    printf("접속이 성공했습니다\n");
                else
                    printf("접속이 실패했습니다\n");
            }
        }
    }
}