#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

int main(void) {
	char pathname[_MAX_PATH];

	_getcwd(pathname, _MAX_PATH);
	printf("%s\n", pathname);

	FILE* fp;
	char buffer[_MAX_ENV];

	//fp = fopen();
}