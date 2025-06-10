// SwapTestApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void swap(int& x, int& y);   // ProtoType

int main()
{
  int x = 10;
  int y = 20;

  cout << "스와핑 전 x, y 값 " << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	swap(x, y);  // Call by reference
	cout << "스와핑 후 x, y 값 " << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	return 0;
}

void swap(int& rX, int& rY)  // Call by reference
{
	int temp = rX;
	rX = rY;
	rY = temp;
}