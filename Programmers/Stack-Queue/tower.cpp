#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<pair<int, int>> s;
	stack<int> ans; // stack�� ���� ���� �� ������ �Ųٷ� answer return

	for (int i = 0; i < heights.size(); i++)
		s.push(pair<int, int>(heights[i], i)); // heights�� stack���� ����

	while (s.size() > 0) {
		int i;
		// stack�� top�� heights�� �ں��� ���ؼ� ū �� ������ ����
		for (i = s.top().second - 1; i >= 0; i--) {
			// ������ �� �ִ� ž�� ������ ��
			if (s.top().first < heights[i]) { 
				ans.push(i + 1); // ans stack�� �װ�
				s.pop(); // stack top pop
				break;
			}
		}
		// ������ ���� ���ϸ� ans�� 0 push
		if (i == -1) {
			ans.push(0);
			s.pop();
		}

	}

	// ans�� ž�� answer�� push_back
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