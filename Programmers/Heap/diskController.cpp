#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


bool compare(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	priority_queue<int, vector<vector<int>>, cmp> pq; // 소요시간 오름차순
	sort(jobs.begin(), jobs.end(), compare);  // jobs 요청시점 오름차순
	int answer = 0;
	int time = 0;
	vector<int> working;
	int total = 0;

	for (int i = 0; i < jobs.size(); i++)
		pq.push(jobs[i]);

	while (!pq.empty()) {
		working = pq.top();

		while (1) {
			if (working[1] == time) {
				if (total - working[0] < 0) {
					total -= time;
					time = 0;
					vector<int> temp = working;
					pq.pop();
					working = pq.top();
					pq.push(temp);
				}
				else {
					answer += (total - working[0]);
					pq.pop();
					time = 0;
					break;
				}
			}
			time++;
			total++;
		}		
	}
	answer /= jobs.size();
	return answer;
}

int main() {
	//vector<vector<int>> jobs = { {0,9},{0,4},{0,5},{ 0,7 },{ 0,3 } };
	vector<vector<int>> jobs = { {0,3},{1,9},{500,6} };
	vector<int> a;

	printf("%d\n", solution(jobs));
	return 0;
}