#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	// ���� ���� �������� �������� ����
	sort(routes.begin(), routes.end());

	// ���� ���� �����ϴ� ���� ���������� ī�޶� ��ġ�ϴ� �ɷ� �����ϰ�
	// �� ���� ���� ������ ���������� ī�޶�ġ ��ġ���� ������
	// �� ���� ���� ��ġ�ϸ� �ּҷ� ��ġ ����
	// ���� ī�޶� ��ġ���� �ʰ� �����ϴ� ���� ������ 
	// �� ���� ������ġ�� �߰� ��ġ
	answer++;
	int camLoc = routes[0][1];
	for (int i = 0; i < routes.size(); i++) {
		if (routes[i][1] < camLoc) {
			camLoc = routes[i][1];
		}
		if (routes[i][0] > camLoc) {
			answer++;
			camLoc = routes[i][1];
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> v = { {-20,15},{-14,-5},{-18,-13},{-5,-3} };

	printf("%d\n", solution(v));
	return 0;
}