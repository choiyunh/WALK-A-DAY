#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	// "BACDE" 에서 B를 받아옴
	// skill에서 B를 찾아
	// 없으면 그냥 통과 인덱스가 0이어도 통과
	// 있으면 skill에서 B보다 앞에있는 문자가 B 뒤애 있는지 찾아
	// 있으면 불가능 없으면 통과
	// 끝까지 통과하면 count++;
	
	return answer;
}

int main() {
	string s = "CBD";
	vector<string> st = { "BACDE","CBADF","AECB" };

	cout << solution(s, st) << endl;
	return 0;
}