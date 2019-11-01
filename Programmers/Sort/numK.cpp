#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int size = commands.size();

	for (int i = 0; i < size; i++) {

		vector<int> subArray;
		subArray.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
		sort(subArray.begin(), subArray.end());
		answer.push_back(subArray[commands[i][2] - 1]);
	}

	return answer;
}

int main() {
	vector<int> array = { 1,2,3 };
	vector<vector<int>> com;

	return 0;
}