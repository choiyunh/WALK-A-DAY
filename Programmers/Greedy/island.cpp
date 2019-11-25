#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	// check �迭�� ���� ����� ������ üũ���ְ�
	// 0 1�� ����Ǿ��� �� 2�� 0�̳� 1 �� �� �Ѱ��̶��� ����ǵ� üũ
	// ��� �������� �������� �����ؼ� ��� ���� �ͺ��� �˻�
	vector<bool> check(4, false);
	sort(costs.begin(), costs.end(), cmp);
	bool flag = true;
	int ix = 0;
	while (true) {
		// �� �� ��� ������� �ʾ����� �� �� �� true
		// �� ���� ������� �ʾҴµ� ������ �� ���� ����Ǿ� �ִ°��
		// �� ���� �����
		if (check[costs[ix][0]] == false) {
			if (check[costs[ix][1]] == false) {
				check[costs[ix][1]] = true;
				check[costs[ix][0]] = true;
			}
			
		}
		
		// ��� ���� ����Ǹ� break
		for (int i = 0; i < check.size(); i++) {
			if (check[i] == false) {
				flag = false;
				break;
			}
		}
		if (flag == true) break;
		
	}
	return answer;
}

int main() {
	int n = 4;
	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

	printf("%d\n", solution(n, costs));
	return 0;
}