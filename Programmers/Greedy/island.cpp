#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	// 연결되어있는 섬들과 그 cost를 저장
	// ex connect[0] 에는 0과 연결되어있는 섬 목록과 , 각각의 cost
	unordered_map<int,vector<pair<int,int>>> connect;
	for (size_t i = 0; i < costs.size(); i++) {
		// 같은 연결은 두 번 주어지지 않으므로
		connect[costs[i][0]].push_back(make_pair(costs[i][1], costs[i][2]));
		connect[costs[i][1]].push_back(make_pair(costs[i][0], costs[i][2]));
	}
	
	return answer;
}

int main() {
	int n = 4;
	vector<vector<int>> costs = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

	printf("%d\n", solution(n, costs));
	return 0;
}