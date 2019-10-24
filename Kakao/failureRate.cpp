#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<pair<double, int>> fR;
	
	for (int i = 1; i <= N; i++) {
		int son = 0, parents = 0;
		for (int t : stages) {
			if (t >= i)
				parents++;
			if (t == i)
				son++;
		}
		fR.push_back(pair<double, int>(son / (double)parents, i));
	}
	sort(fR.begin(), fR.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(fR[i].second);
		
	return answer;
}

int main() {
	int N = 5;
	vector<int> s = { 4,4,4,4,4 };
	vector<int> ans = solution(N, s);

	for (int i : ans)
		printf("%d\n", i);
	return 0;
}