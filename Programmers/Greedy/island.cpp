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
	// check �迭�� ���� �湮 ���� üũ
	// 0 1�� ����Ǿ��� �� 2�� 0�̳� 1 �� �� �Ѱ��̶��� ����� �� �ٸ� �Ǽ�
	// ��� �������� �������� �����ؼ� ��� ���� �ͺ��� �˻�
	vector<bool> check(4, false);
	vector<bool> pass(costs.size(), false);
	sort(costs.begin(), costs.end(), cmp);
	int cnt = 0;
	
	// ���� ��� ���� ù��° �ٸ� �Ǽ��ϰ� ����
	check[costs[0][0]] = true;
	check[costs[0][1]] = true;
	pass[0] = true;
	answer += costs[0][2];
	cnt += 2;

	// cnt -> �湮������ ���� ����
	while (cnt < n) {
		for (int i = 1; i < costs.size(); i++) {
			if (pass[i]) continue;

			if (!check[costs[i][0]] && check[costs[i][1]]) {
				check[costs[i][0]] = true;
				pass[i] = true; // �ش� cost�� �� �ΰ��� �� �� �湮 ���������Ƿ�
				cnt++;
				answer += costs[i][2];
				break; // �ٸ� �Ǽ������� �ٽ� ó������ üũ
			}
			else if (check[costs[i][0]] && !check[costs[i][1]]) {
				check[costs[i][1]] = true;
				pass[i] = true; // �ش� cost�� �� �ΰ��� �Ѵ� �湮 ���������Ƿ�
				cnt++;
				answer += costs[i][2];
				break; // �ٸ� �Ǽ������� �ٽ� ó������ üũ
			}
		}		
	}
	return answer;
}

int main() {
	int n = 4;
	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

	printf("%d\n", solution(n, costs));
	return 0;
}