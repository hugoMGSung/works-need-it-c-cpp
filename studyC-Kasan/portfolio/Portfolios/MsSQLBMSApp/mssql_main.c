#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <stdio.h>

void show_error(unsigned int handletype, const SQLHANDLE handle)
{
	SQLCHAR sqlstate[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
		printf("Message: %s \nSQLSTATE: %s\n", message, sqlstate);
}

int main()
{
	SQLHANDLE sqlenvhandle;
	SQLHANDLE sqlconnectionhandle;
	SQLHANDLE sqlstatementhandle;
	SQLRETURN retcode;

	do
	{
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			break;

		if (SQL_SUCCESS != SQLSetEnvAttr(sqlenvhandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			break;

		SQLCHAR retconstring[1024];
		switch (SQLDriverConnect(sqlconnectionhandle, NULL,
			(SQLCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=bms;UID=sa;PWD=mssql_p@ssw0rd;",
			SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT))
		{
		case SQL_SUCCESS_WITH_INFO:
			show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
			break;
		case SQL_INVALID_HANDLE:
		case SQL_ERROR:
			show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
			retcode = -1;
			break;
		default:
			break;
		}

		if (retcode == -1)
			break;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			break;

		if (SQL_SUCCESS != SQLExecDirect(sqlstatementhandle, (SQLCHAR*)L"select * from books_info", SQL_NTS))
		{
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			break;
		}
		else
		{
			char title[64];
			char writer[64];
			int id;
			while (SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
			{
				SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &id, 0, NULL);
				SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, title, 100, NULL);
				SQLGetData(sqlstatementhandle, 3, SQL_C_CHAR, writer, 100, NULL);
				printf("%s  %s %s\n", id, title, writer);
			}
		}
	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
	SQLDisconnect(sqlconnectionhandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

}