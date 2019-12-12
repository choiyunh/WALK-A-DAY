#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> term;

	// 각 기능개발에 걸리는 시간
	for (int i = 0; i < progresses.size(); i++) {
		if ((100 - progresses[i]) % speeds[i] != 0)
			term.push_back(((100 - progresses[i]) / speeds[i]) + 1);
		else
			term.push_back(((100 - progresses[i]) / speeds[i]));
	}

	// 첫 개발을 배포일로 잡고
	int day = term[0];	
	int release = 1; // 배포 시점에 몇가지 기능을 배포하는지
	for (int i = 1; i < term.size(); i++) {
		// 
		if (term[i] <= day)
			release++;
		else {
			answer.push_back(release);
			release = 1;
			day = term[i];
		}
	}
	answer.push_back(release);
	
	return answer;
}

int main() {
	vector<int> progresses = { 93,30,55 };
	vector<int> speeds = { 1,30,5 };
	vector<int> ans = solution(progresses, speeds);

	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;	
}