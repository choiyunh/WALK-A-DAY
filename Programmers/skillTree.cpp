#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	// "BACDE" ���� B�� �޾ƿ�
	// skill���� B�� ã��
	// ������ �׳� ��� �ε����� 0�̾ ���
	// ������ skill���� B���� �տ��ִ� ���ڰ� skill_trees[i]�� B �ڿ� �ִ��� ã��
	// ������ �Ұ��� ������ ���
	// ������ ����ϸ� count++;
	for (int i = 0; i < skill_trees.size(); i++) {
		string temp = skill_trees[i];
		for (int j = 0; j < temp.size(); j++) {
			char c = temp[j];
			if (skill[j] == c) {
				if (j == 0) break;
				
			}
		}
	}
	return answer;
}

int main() {
	string s = "CBD";
	vector<string> st = { "BACDE","CBADF","AECB" };

	cout << solution(s, st) << endl;
	return 0;
}