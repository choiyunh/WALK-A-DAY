#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<pair<int, int>> s;
	stack<int> ans; // stack에 정답 저장 후 위부터 거꾸로 answer return

	for (int i = 0; i < heights.size(); i++)
		s.push(pair<int, int>(heights[i], i)); // heights를 stack으로 만듬

	while (s.size() > 0) {
		int i;
		// stack의 top과 heights의 뒤부터 비교해서 큰 거 나오면 수신
		for (i = s.top().second - 1; i >= 0; i--) {
			// 수신할 수 있는 탑을 만났을 때
			if (s.top().first < heights[i]) { 
				ans.push(i + 1); // ans stack에 쌓고
				s.pop(); // stack top pop
				break;
			}
		}
		// 끝까지 수신 못하면 ans에 0 push
		if (i == -1) {
			ans.push(0);
			s.pop();
		}

	}

	// ans의 탑을 answer에 push_back
	while (ans.size() > 0) {
		answer.push_back(ans.top());
		ans.pop();
	}
	return answer;
}

int main() {
	vector<int> t = { 6,9,5,7,4 };

	vector<int> ans = solution(t);

}