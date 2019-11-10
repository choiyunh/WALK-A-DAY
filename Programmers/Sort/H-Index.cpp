#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int cnt = 0;
	sort(citations.begin(), citations.end());
	int n = citations.size();
	while(1){
		for (int i = 0; i < n; i++) {
			if (citations[i] >= answer)
				cnt++;
		}
		if (cnt < answer) {
			answer--;
			break;
		}
		cnt = 0;
		answer++;
	}
	return answer;
}

int main() {
	vector<int> c = { 0,0,0 };
	printf("%d\n", solution(c));
	return 0;
}