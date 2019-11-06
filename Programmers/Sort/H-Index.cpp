#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	int n = citations.size();

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] <= n - i)
			answer = citations[i];
	}

	if (answer == 0) {
		answer = n;
	}
	return answer;
}

int main() {
	vector<int> c = { 42,7,5 };
	printf("%d\n", solution(c));
	return 0;
}