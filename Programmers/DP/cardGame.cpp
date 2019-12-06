#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	queue<int> leftQ;
	queue<int> rightQ;

	// 모든 카드를 큐에 삽입
	for (int i = 0; i < left.size(); i++) {
		leftQ.push(left[i]);
		rightQ.push(right[i]);
	}

	int answer = 0;
	// 두 큐 중 하나라도 빌 때까지 진행
	while (!leftQ.empty() && !rightQ.empty()) {

		// 왼쪽 오른쪽 카드 비교
		int LTop = leftQ.front();
		int RTop = rightQ.front();

		// 오른쪽이 작으면 점수 UP
		if (RTop < LTop) {
			answer += RTop;
			rightQ.pop();
		}
		// 오른쪽이 크면 왼쪽카드 버리기
		else {
			leftQ.pop();
		}
	}
	return answer;
}

int main() {

	return 0;
}