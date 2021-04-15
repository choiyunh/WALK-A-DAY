#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q; // 우선순위와 위치를 저장할 큐
	priority_queue<int> pq; // 우선순위큐

	int cnt = 0;

	for (int i = 0; i < priorities.size(); i++) {
		
		q.push(pair<int, int>(i, priorities[i]));
		pq.push(priorities[i]);
	}
	
	int count = 0; // 인쇄한 횟수
	while (1) {
		if (q.front().second == pq.top()) { // 우선순위큐의 front와 큐의 front가 같으면 인쇄
			if (q.front().first == location) {// 단 위치가 location과 같으면 break후 count return
				count++;
				break;
			}
			q.pop();
			pq.pop();
			count++;
		}
		else { // 다르면 큐의 front를 맨 뒤로 push
			q.push(q.front());
			q.pop();
		}
	}
	answer = count;
	return answer;
}

int main() {
	vector<int> p = { 2,1,3,2 };
	int loc = 2;

	int ans = solution(p, loc);

	printf("%d\n", ans);

	return 0;
}
