#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int sum = brown + red;
	int x = 0, y = 0;

	for (int i = 3; i <= sum; i++) {
		// ������ �������� ������ ���� �򺸴� ���� ��(������ �� y �� x)
		// �ѷ� �ΰ� �ִ� ���� ����ؼ� �� ���� red�� ���� ��
		if (sum % i == 0 && sum / i >= i && (sum-(((sum/i) * 2) + ((i - 2) * 2))) == red) { 
			x = sum / i;
			y = i;
		}
	}

	answer.push_back(x);
	answer.push_back(y);
	return answer;
}

int main() {
	int b = 24;
	int r = 24;

	vector<int> s = solution(b, r);

	for (int t : s)
		printf("%d\n", t);

	return 0;
}