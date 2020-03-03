utej?
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> s; // ���� ���ڸ� ������ stack
	
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') { // '('�� ������ push(������ �����̰ų� �������� ����)
			s.push(arrangement[i]);
		}
		else { // ')'�� ������ �տ��Ÿ� ���� ���������� ������ ������ �Ǵ�
			if (arrangement[i - 1] == '(') { // �������϶�
				s.pop();
				answer += s.size(); // ���ÿ� (�� �׿��ִ� ��ŭ ������ ������ �ְ� ���⼭ �߸��Ƿ� size��ŭ �����ָ� �߸����� ���� ����
			}
			else if (arrangement[i - 1] == ')') { // ������ ���� ��
				s.pop();
				answer++; // ������ ���� ���� ������ ���������� ���������� ���� �����鼭 1�� �����ָ� ��
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