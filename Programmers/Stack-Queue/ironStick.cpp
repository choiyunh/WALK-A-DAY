utej?
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> s; // 들어올 문자를 저장할 stack
	
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') { // '('가 들어오면 push(막대의 시작이거나 레이저의 시작)
			s.push(arrangement[i]);
		}
		else { // ')'가 들어오면 앞에거를 보고 레이저인지 막대의 끝인지 판단
			if (arrangement[i - 1] == '(') { // 레이저일때
				s.pop();
				answer += s.size(); // 스택에 (가 쌓여있는 만큼 막대의 시작이 있고 여기서 잘리므로 size만큼 더해주면 잘린기준 왼쪽 갯수
			}
			else if (arrangement[i - 1] == ')') { // 막대의 끝일 때
				s.pop();
				answer++; // 레이져 기준 왼쪽 갯수는 레이져에서 더해줬으니 막대 끝나면서 1씩 더해주면 됨
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