#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> num(3);
	int max = 0;

	int first[5] = { 1,2,3,4,5 };
	int second[8] = { 2,1,2,3,2,4,2,5 };
	int third[10] = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); i++) {
		if (first[i % 5] == answers[i])
			num[0]++;
		if (second[i % 8] == answers[i])
			num[1]++;
		if (third[i % 10] == answers[i])
			num[2]++;
	}
	max = num[0];
	if (num[1] < num[2]) {
		if (max < num[2])
			max = num[2];
	}
	else
		if (max < num[1])
			max = num[1];
	
	for (int i = 0; i < 3; i++) {
		if (num[i] == max) answer.push_back(i + 1);
	}
	return answer;
}

int main() {
	vector<int> a = { 1,3,2,4,2 };
	vector<int> result = solution(a);

	printf("%d\n", result[2]);
	return 0;
}