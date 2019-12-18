#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> s;
	
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			s.push(arrangement[i]);
		}
		else {
			if (arrangement[i - 1] == '(') {
				s.pop();
				answer += s.size();
			}
			else if (arrangement[i - 1] == ')') {
				s.pop();
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	string arr = { "()(((()())(())()))(())" };

	printf("%d\n", solution(arr));
	return 0;
}