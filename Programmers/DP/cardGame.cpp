#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	queue<int> leftQ;
	queue<int> rightQ;

	// ��� ī�带 ť�� ����
	for (int i = 0; i < left.size(); i++) {
		leftQ.push(left[i]);
		rightQ.push(right[i]);
	}

	int answer = 0;
	// �� ť �� �ϳ��� �� ������ ����
	while (!leftQ.empty() && !rightQ.empty()) {

		// ���� ������ ī�� ��
		int LTop = leftQ.front();
		int RTop = rightQ.front();

		// �������� ������ ���� UP
		if (RTop < LTop) {
			answer += RTop;
			rightQ.pop();
		}
		// �������� ũ�� ����ī�� ������
		else {
			leftQ.pop();
		}
	}
	return answer;
}

int main() {

	return 0;
}