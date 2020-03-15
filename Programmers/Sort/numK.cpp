#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> temp; // i���� j���� �߶� ������ �ӽ� ����

	for (size_t i = 0; i < commands.size(); i++) {
		temp.assign(array.begin() + (commands[i][0] - 1),
		array.begin() + (commands[i][1])); // assing(b,e)-> �ݺ��� ������ �Ҵ��� array�� i���� j���� temp�� �Ҵ�
		sort(temp.begin(), temp.end()); // ����
		answer.push_back(temp[commands[i][2] - 1]); // k��° ���� answer�� ����
	}


	return answer;
}

int main() {
	vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> com = { {2,5,3},{4,4,1},{1,7,3} };
	vector<int> s = solution(array, com);
	printf("%d\n", s[0]);
	return 0;
}
