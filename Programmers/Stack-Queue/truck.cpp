#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int curWeight = 0;
	int i = 0;

	while (1) {
		if (q.size() == bridge_length) { // 다리의 끝에 트럭이 도착했을 때 pop
			curWeight -= q.front();
			q.pop();
		}
		answer++; // 새 트럭이든 0이든 push하면 시간이 지나감 answer++
		if (curWeight + truck_weights[i] <= weight) {// 현재 무게에 새 트럭의 무게를 더했을 때 견딜 수 있으면 (더한 값이 작거나 !!같으면!!)
			curWeight += truck_weights[i]; // 현재 무게를 더해주고
			q.push(truck_weights[i++]); // 새 트럭을 push할 때 i++
			
			if (i == truck_weights.size()) { // 마지막 트럭이 다리에 올랐으면 bridge_length를 더해주고 끝
				answer += bridge_length;
				break;
			}
		}
		else { // 새 트럭을 견딜 수 없으면 0을 push
			q.push(0);
		}		
	}
	return answer;
}

int main() {
	int bl =100;
	int w = 100;
	vector<int> t_w = {10,10,10,10,10,10,10,10,10,10};
	//vector<int> t_w = { 7,4,5,6 };

	printf("%d\n", solution(bl, w, t_w));
	return 0;
}