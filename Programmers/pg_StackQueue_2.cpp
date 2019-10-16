#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<int> q;
	int cnt = 0;

	for (int i = 0; i < priorities.size(); i++)
		q.push(priorities[i]);

	int i = 1;
	for (i = 1; i < priorities.size();i++) {
		if (q.front() < priorities[i]) {
			int temp = q.front();
			q.pop();
			q.push(temp);
			i = 1;
		}
	}
	if (i == 4)
		q.pop();
	return answer;
}

int main() {
	vector<int> p = { 2,1,3,2 };
	int loc = 2;

	queue<int> pq;
	
	int ans = solution(p, loc);
	printf("%d\n", pq.back());
	return 0;
}