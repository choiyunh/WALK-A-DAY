#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
	if (a[0] == b[0])
		return a[1] < b[1];
	else
		return a[0] < b[0];
}

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		if (a[1] == b[1])
			return a[0] > b[0];
		else
			return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int total = 0;
	int num = jobs.size();
	sort(jobs.begin(), jobs.end(), compare); // jobs ��û�ð� �������� ����
	priority_queue<vector<int>,vector<vector<int>>,cmp> pq; // �ҿ�ð� �������� �켱���� ť(�ؾ� �� �� ����)

	while (!jobs.empty() || !pq.empty()) { 	
		if (pq.empty()) { 
			pq.push(jobs.front());  // �켱 ó�� ��û�� ���� �켱����ť�� ����
			jobs.erase(jobs.begin());
			total = pq.top()[0] + pq.top()[1]; // �� �帥 �ð� (��û�ð�+�ҿ�ð�)
			answer += total - pq.top()[0]; // ��û���� ������� �ɸ� �ð��� �� �帥 �ð� - ��û�ð�
		}
		pq.pop(); //���� ������ �� pop
		while (!jobs.empty() && total > jobs.front()[0]) { // ���� �ϴ� �� �߿� ��û�� ������
			pq.push(jobs.front()); // �켱����ť�� �� �� �߰�
			jobs.erase(jobs.begin()); 			
		}
		if (!pq.empty()) {  // �� ���� ����������
			total += pq.top()[1];  // �ð����
			answer += total - pq.top()[0];
		}		
	}
	return answer / num;
}

int main() {
	//vector<vector<int>> jobs = { {0,3},{1,9},{2,6}}; // �� 9
	//vector<vector<int>> jobs = { {0,9},{0,4},{0,5},{ 0,7 },{ 0,3 } }; // �� 13
	//vector<vector<int>> jobs = { {1,9},{1,4},{1,5},{1,7},{1,3} }; // �� 13
	//vector<vector<int>> jobs = { {0,5},{1,2},{5,5}}; // �� 6
	vector<vector<int>> jobs = { {24,10},{18,39},{34,20},{37,5},{47,22},{20,47},{15,2},{15,34},{35,43},{26,1} };// ��74
	printf("%d\n", solution(jobs));
	return 0;
}