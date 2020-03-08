#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	vector<int> pq; // priority_queue���� �ּڰ� �ٷ�� ��ٷο�Ƿ� �׳� vector

	while (!operations.empty()) {
		char com = operations[0][0]; // ���� ��ɾ��� ��ɾ�κ� ����
		int data = atoi(operations[0].substr(2).c_str()); // data ���� 

		if (com == 'I') { // ��ɾ 'I'�� ����
			pq.push_back(data);
			sort(pq.begin(), pq.end(), greater<int>()); // ������ ������ �������� ����
		}
		else if (com == 'D' && !pq.empty()) { // 'D'�� ����
			if (data == 1) 	pq.erase(pq.begin()); // �ִ� ����(�������� ���ĵ������Ƿ�)
			else pq.erase(pq.begin() + (pq.size() - 1)); // �ּڰ� ���� (pq.erase(pq.begin() + index) -> �ش� index erase
		}
		operations.erase(operations.begin()); // ������ ����̹Ƿ� ����
	}

	if (pq.empty()) { // ť�� ���������
		answer.push_back(0);
		answer.push_back(0);
	}

	else if (pq.size() == 1) // ť�� ���� �ϳ�
		answer.push_back(pq.front());

	else { // �� �� �̻��̸� �ִ�, �ּڰ� ���
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