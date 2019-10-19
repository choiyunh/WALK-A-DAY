#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> onBridge;
	int curWeight = 0;
	int i = 0;
		
	while (1) {
		answer++;
		if (onBridge.size() == bridge_length) {
			if (curWeight == 0) {
				answer--;
				break;
			}
			
			curWeight -= onBridge.front();
			onBridge.pop();
		}

		if (i < truck_weights.size()) {
			curWeight += truck_weights[i];
			if (curWeight <= weight) {
				onBridge.push(truck_weights[i++]);
			}
			else {
				curWeight -= truck_weights[i];
				onBridge.push(0);
			}
		}
		else {
			onBridge.push(0);
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