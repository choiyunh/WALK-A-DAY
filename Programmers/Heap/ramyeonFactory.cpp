#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	int i = 0, j = 0; // i�� ��¥(0�Ϻ���), j�� �ε���
	while (i < k) {
		if (i == dates[j]) { // ���޳��� �Ǹ�
			pq.push(supplies[j]); // pq�� push (MAX HEAP)
			if (j < dates.size()-1) j++; 
		}

		if (stock == 0) { // �а��簡 �� ��������
			answer++; 
			stock += pq.top(); // MAX HEAP�̹Ƿ� ��¥ ������ �ƴ� �� ������ ����
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