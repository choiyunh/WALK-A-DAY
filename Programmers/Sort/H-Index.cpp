#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> citations) {

	sort(citations.begin(), citations.end(), greater<int>());
	int answer = 0;
	int cnt = 0;
	while (1) {
	

		if (citations.size() - cnt <= answer) {
			return answer;
		}
		else {
			answer++;
		}
	}

	return answer;
}

int main() {
	vector<int> c = { 3,0,6,1,5 };

	printf("%d\n", solution(c));

	return 0;
}