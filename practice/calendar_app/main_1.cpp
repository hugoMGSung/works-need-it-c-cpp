#include <iostream>
#include "Calendar.h"
#include <Windows.h>

using namespace std;

int main()
{
	std::locale::global(std::locale("kor"));
	SetConsoleOutputCP(65001);
	Calendar c;

	int year, column;
	cout << "³âµµ: ";
	cin >> year;

	c.setYear(year);
	c.print(4);

	return 0;
}