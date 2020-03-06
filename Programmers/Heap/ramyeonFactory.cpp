#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	int i = 0, j = 0; // i는 날짜(0일부터), j는 인덱스
	while (i < k) {
		if (i == dates[j]) { // 공급날이 되면
			pq.push(supplies[j]); // pq에 push (MAX HEAP)
			if (j < dates.size()-1) j++; 
		}

		if (stock == 0) { // 밀가루가 다 떨어지면
			answer++; 
			stock += pq.top(); // MAX HEAP이므로 날짜 빠른게 아닌 양 많은거 부터
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