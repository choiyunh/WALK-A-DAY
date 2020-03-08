#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	vector<int> pq; // priority_queue쓰면 최솟값 다루기 까다로우므로 그냥 vector

	while (!operations.empty()) {
		char com = operations[0][0]; // 들어온 명령어의 명령어부분 저장
		int data = atoi(operations[0].substr(2).c_str()); // data 저장 

		if (com == 'I') { // 명령어가 'I'면 삽입
			pq.push_back(data);
			sort(pq.begin(), pq.end(), greater<int>()); // 삽입할 때마다 내림차순 정렬
		}
		else if (com == 'D' && !pq.empty()) { // 'D'면 삭제
			if (data == 1) 	pq.erase(pq.begin()); // 최댓값 삭제(내림차순 정렬돼있으므로)
			else pq.erase(pq.begin() + (pq.size() - 1)); // 최솟값 삭제 (pq.erase(pq.begin() + index) -> 해당 index erase
		}
		operations.erase(operations.begin()); // 수행한 명령이므로 삭제
	}

	if (pq.empty()) { // 큐가 비어있으면
		answer.push_back(0);
		answer.push_back(0);
	}

	else if (pq.size() == 1) // 큐에 값이 하나
		answer.push_back(pq.front());

	else { // 두 개 이상이면 최댓값, 최솟값 출력
		answer.push_back(pq.front());
		answer.push_back(pq.back());
	}
	return answer;
}

int main() {
	vector<string> s = { "I 16","I -5643","D -1","D 1","D 1","I 123","D -1" };

	printf("%d\n", solution(s)[0]);
	return 0;
}