#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	// "BACDE" ���� B�� �޾ƿ�
	// skill���� B�� ã��
	// ������ �׳� ��� �ε����� 0�̾ ���
	// ������ skill���� B���� �տ��ִ� ���ڰ� B �ھ� �ִ��� ã��
	// ������ �Ұ��� ������ ���
	// ������ ����ϸ� count++;
	
	return answer;
}

int main() {
	string s = "CBD";
	vector<string> st = { "BACDE","CBADF","AECB" };

	cout << solution(s, st) << endl;
	return 0;
}