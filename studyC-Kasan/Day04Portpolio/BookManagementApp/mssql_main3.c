//include the below additional libraries
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdio.h>

int main() {
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
    //define handles and variables
    SQLHANDLE conn;
    SQLHANDLE stmt;
    SQLHANDLE env;
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
    //initializations
    conn = NULL;
    stmt = NULL;
    //allocations
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env))
        goto COMPLETED;
    if (SQL_SUCCESS != SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
        goto COMPLETED;
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, env, &conn))
        goto COMPLETED;
    //output
    printf("Attempting connection to SQL Server...\n");
    //connect to SQL Server  
    //I am using a trusted connection and port 14808
    //it does not matter if you are using default or named instance
    //just make sure you define the server name and the port
    //You have the option to use a username/password instead of a trusted connection
    //but is more secure to use a trusted connection
    switch (SQLDriverConnect(conn,
        NULL,
        (SQLWCHAR*)"DRIVER={SQL Server};SERVER=localhost, 1433; DATABASE=bms; UID=sa; PWD=password;",
        //(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=bms;Trusted=true;",
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_NOPROMPT)) {
    case SQL_SUCCESS:
        printf("Successfully connected to SQL Server\n");
        break;
    case SQL_SUCCESS_WITH_INFO:
        printf("Successfully connected to SQL Server\n");
        break;
    case SQL_INVALID_HANDLE:
        printf("Could not connect to SQL Server\n");
        goto COMPLETED;
    case SQL_ERROR:
        printf("Could not connect to SQL Server\n");
        goto COMPLETED;
    default:
        break;
    }
    //if there is a problem connecting then exit application
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, conn, &stmt))
        goto COMPLETED;
    //output
    printf("\n");
    printf("Executing T-SQL query...\n");
    //if there is a problem executing the query then exit application
    //else display query result
    if (SQL_SUCCESS != SQLExecDirect(stmt, (SQLWCHAR*)"SELECT * FROM books_info", SQL_NTS)) {
        printf("Error querying SQL Server\n");
        goto COMPLETED;
    }
    else {
        //declare output variable and pointer
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLINTEGER ptrSqlVersion;
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            SQLGetData(stmt, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
            //display query result
            printf("\nQuery Result:\n\n");
            printf("%s\n", sqlVersion);
        }
    }
    //close connection and free resources
COMPLETED:
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
    SQLDisconnect(conn);
    SQLFreeHandle(SQL_HANDLE_DBC, conn);
    SQLFreeHandle(SQL_HANDLE_ENV, env);
    //pause the console window - exit when key is pressed
    printf("\nPress any key to exit...\n");
    getchar();
}
