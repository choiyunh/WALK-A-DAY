#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	int size = prices.size();
	vector<int> answer(size);
	stack<int> s;

	for (int i = 0; i < size; i++) {
		while (!s.empty() && prices[i] < prices[s.top()]) { // 가격이 떨어질 때
			answer[s.top()] = i - s.top(); // 현재 시간(i)에서 떨어지기 전 시간(s.top)을 뺀 값을 answer의 해당 시간index에 저장
			s.pop(); 
		}
		s.push(i); // 시간(초) push
	}

	while (!s.empty()) { // 가격이 떨어지지 않은 것들 처리
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}
	return answer;
}
