#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	int i = 0, j = 0;
	while (i < k) {
		if (i == dates[j]) {
			pq.push(supplies[j]);
			if (j < dates.size()-1) j++;
		}

		if (stock == 0) {
			answer++;
			stock += pq.top();
			pq.pop();
		}
		stock--;
		i++;
	}

	return answer;
}

int main() {
	int s = 4;
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;

	printf("%d\n", solution(s, dates, supplies, k));
	return 0;
}