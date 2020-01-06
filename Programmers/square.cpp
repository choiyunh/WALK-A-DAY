#include <iostream>
using namespace std;

long long solution(int w, int h)
{	//w = 8, h = 12의 원래 직사각형에서는 정사각형 96개 사용가능(8*12)
	//대각선으로 그으면 총 16개를 사용할 수 없음
	//정사각형일 때 -> h만큼 사용못함
	//직사각형일 때 -> w*2만큼 사용못함
	long long answer = 1;
	if (w == h)
		answer = (w * h) - h;
	else
		answer = (w * h) - (w * 2);
	return answer;
}

int main() {
	int w = 8;
	int h = 12;
	cout << solution(w, h) << endl;
	return 0;
}