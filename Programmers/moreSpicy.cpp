#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i : scoville)
		pq.push(i);

	while (pq.top() < K) {
		if (pq.size() == 1)
			return -1;
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + (b * 2));
		answer++;
	}
	return answer;

}

int main() {
	vector<int> s = { 1,2,3,9,10,12 };
	int k = 700;
	
	printf("%d\n", solution(s, k));

	return 0;
}