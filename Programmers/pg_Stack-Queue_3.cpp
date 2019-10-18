#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<pair<int, int>> s;
	stack<int> ans;

	for (int i = 0; i < heights.size(); i++)
		s.push(pair<int, int>(heights[i], i));

	while (s.size() > 0) {
		int i;
		for (i = s.top().second - 1; i >= 0; i--) {
			if (s.top().first < heights[i]) {
				ans.push(i + 1);
				s.pop();
				break;
			}
		}
		if (i == -1) {
			ans.push(0);
			s.pop();
		}

	}

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