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
	sort(jobs.begin(), jobs.end(), compare); // jobs 요청시간 오름차순 정렬
	priority_queue<vector<int>,vector<vector<int>>,cmp> pq; // 소요시간 오름차순 우선순위 큐(해야 될 일 쌓임)

	while (!jobs.empty() || !pq.empty()) { 	
		if (pq.empty()) { 
			pq.push(jobs.front());  // 우선 처음 요청된 일을 우선순위큐에 삽입
			jobs.erase(jobs.begin());
			total = pq.top()[0] + pq.top()[1]; // 총 흐른 시간 (요청시간+소요시간)
			answer += total - pq.top()[0]; // 요청에서 종료까지 걸린 시간은 총 흐른 시간 - 요청시간
		}
		pq.pop(); //지금 진행할 일 pop
		while (!jobs.empty() && total > jobs.front()[0]) { // 현재 하는 일 중에 요청이 들어오면
			pq.push(jobs.front()); // 우선순위큐에 할 일 추가
			jobs.erase(jobs.begin()); 			
		}
		if (!pq.empty()) {  // 할 일이 남아있으면
			total += pq.top()[1];  // 시간계산
			answer += total - pq.top()[0];
		}		
	}
	return answer / num;
}

int main() {
	//vector<vector<int>> jobs = { {0,3},{1,9},{2,6}}; // 답 9
	//vector<vector<int>> jobs = { {0,9},{0,4},{0,5},{ 0,7 },{ 0,3 } }; // 답 13
	//vector<vector<int>> jobs = { {1,9},{1,4},{1,5},{1,7},{1,3} }; // 답 13
	//vector<vector<int>> jobs = { {0,5},{1,2},{5,5}}; // 답 6
	vector<vector<int>> jobs = { {24,10},{18,39},{34,20},{37,5},{47,22},{20,47},{15,2},{15,34},{35,43},{26,1} };// 답74
	printf("%d\n", solution(jobs));
	return 0;
}