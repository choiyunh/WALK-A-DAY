#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq; // MIN HEAP (오름차순)

	for (int i : scoville) // MIN HEAP에 자료 삽입
		pq.push(i);

	while (pq.top() < K) { // pq의 top이 K이상이면 끝
		if (pq.size() == 1) // 음식을 섞어도 K이상이 안될 때
			return -1;
		// pq의 top을 순서대로 두 개 꺼내서 (a+b*2)해서 다시 push
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + (b * 2));
		answer++; // 섞은횟수 ++
	}
	return answer;

}

int main() {
	vector<int> s = { 1,2,3,9,10,12 };
	int k = 700;
	
	printf("%d\n", solution(s, k));

	return 0;
}