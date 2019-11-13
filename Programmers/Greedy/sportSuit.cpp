#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	int cnt = 0; // ü������ ���� �������� ������ ���� �� �ִ� ��
	int lostNum = lost.size();

	// ������������ �Ⱥ����� �Ǵ� ����� ���� üũ�ؼ�
	// lost�� rserve�迭���� ����
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				cnt++;
				i--; // lost.earse �����Ƿ� i--
				break;
			}
		}
	}
	// �ٸ� ������� ������ �ϴ� ��� üũ
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			// �� ������� üũ( �� ����� �޵޻�����׵� ������ �� �ֱ� ������)
			// �տ��� ���� �� ������ ������ break;
			if (reserve[j] == lost[i] - 1) {
				cnt++;
				reserve.erase(reserve.begin() + j);
				break;
			}
			// �� ������� �� ������ �޻������ ������
			if (reserve[j] == lost[i] + 1) {
				cnt++;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}
	}
	
	answer -= (lostNum - cnt);
	return answer;
}

int main() {
	int n = 5;
	vector<int> l = { 2,3,4 };
	vector<int> r = { 3,4,5 };

	printf("%d\n", solution(n, l, r));
	return 0;
}