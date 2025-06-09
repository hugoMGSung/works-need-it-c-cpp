// ReferenceTestApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;\

int main()
{
		// Creation of reference relations
		int score = 92;
		int& rScore = score;
		// 데이터 변수 사용
		cout << "데이터 변수를 통해 값에 접근" << endl;
		cout << "score: " << score << endl;
		// 참조 변수 사용
		cout << "참조 변수를 통해 값에 접근" << endl;
		cout << "rScore: " << rScore;

		return 0;
}