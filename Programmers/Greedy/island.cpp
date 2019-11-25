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
	// check 배열을 만들어서 연결된 지점을 체크해주고
	// 0 1이 연결되었을 때 2가 0이나 1 둘 중 한곳이랑만 연결되도 체크
	// 비용 기준으로 오름차순 정렬해서 비용 적은 것부터 검사
	vector<bool> check(4, false);
	sort(costs.begin(), costs.end(), cmp);
	bool flag = true;
	int ix = 0;
	while (true) {
		// 두 섬 모두 연결되지 않았으면 두 섬 다 true
		// 한 섬은 연결되지 않았는데 나머지 한 섬이 연결되어 있는경우
		// 그 섬과 연결된
		if (check[costs[ix][0]] == false) {
			if (check[costs[ix][1]] == false) {
				check[costs[ix][1]] = true;
				check[costs[ix][0]] = true;
			}
			
		}
		
		// 모든 섬이 연결되면 break
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