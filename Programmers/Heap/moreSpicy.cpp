#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq; // MIN HEAP (��������)

	for (int i : scoville) // MIN HEAP�� �ڷ� ����
		pq.push(i);

	while (pq.top() < K) { // pq�� top�� K�̻��̸� ��
		if (pq.size() == 1) // ������ ��� K�̻��� �ȵ� ��
			return -1;
		// pq�� top�� ������� �� �� ������ (a+b*2)�ؼ� �ٽ� push
		int a = pq.top(); 
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + (b * 2));
		answer++; // ����Ƚ�� ++
	}
	return answer;

}

int main() {
	vector<int> s = { 1,2,3,9,10,12 };
	int k = 700;
	
	printf("%d\n", solution(s, k));

	return 0;
}