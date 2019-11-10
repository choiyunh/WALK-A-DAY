#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> num;
	int cnt = 0;

	for (int temp : answers) {
		int i = 1;
		if (i == temp)
			cnt++;
		i++;
	}
	num.push_back(cnt);
	cnt = 0;
	for (int i = 0; i < answers.size();i++) {
		int temp = 2;
		if (i % 2 == 0) {
			temp = 2;
		}
		else {
			temp = i % 9;
		}
		if (temp == answers[i])
			cnt++;
	}
	num.push_back(cnt);
	cnt = 0;
	for (int temp : answer) {
		int i = 1;
		if (i == temp)
			cnt++;
	}
	num.push_back(cnt);
	cnt = 0;

	return answer;
}

int main() {
	vector<int> a = { 1,2,3,4,5 };
	vector<int> result = solution(a);
	return 0;
}