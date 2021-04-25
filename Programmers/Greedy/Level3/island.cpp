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
	// check 배열을 만들어서 방문 가능 체크
	// 0 1이 연결되었을 때 2가 0이나 1 둘 중 한곳이랑만 연결될 때 다리 건설
	// 비용 기준으로 오름차순 정렬해서 비용 적은 것부터 검사
	vector<bool> check(4, false);
	vector<bool> pass(costs.size(), false);
	sort(costs.begin(), costs.end(), cmp);
	int cnt = 0;

	// 제일 비용 적은 첫번째 다리 건설하고 시작
	check[costs[0][0]] = true;
	check[costs[0][1]] = true;
	pass[0] = true;
	answer += costs[0][2];
	cnt += 2;

	// cnt -> 방문가능한 섬의 갯수
	while (cnt < n) {
		for (int i = 1; i < costs.size(); i++) {
			if (pass[i]) continue;

			if (!check[costs[i][0]] && check[costs[i][1]]) {
				check[costs[i][0]] = true;
				pass[i] = true; // 해당 cost의 섬 두개는 둘다 방문 가능이므로 패스~
				cnt++;
				answer += costs[i][2];
				break; // 다리 건설했으면 다시 처음부터 체크
			}
			else if (check[costs[i][0]] && !check[costs[i][1]]) {
				check[costs[i][1]] = true;
				pass[i] = true; // 해당 cost의 섬 두개는 둘다 방문 가능이므로 패스~
				cnt++;
				answer += costs[i][2];
				break; // 다리 건설했으면 다시 처음부터 체크
			}
		}

	}
	return answer;
}