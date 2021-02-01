#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> temp; // i부터 j까지 잘라서 저장할 임시 벡터

	for (size_t i = 0; i < commands.size(); i++) {
		temp.assign(array.begin() + (commands[i][0] - 1),
		array.begin() + (commands[i][1])); // assing(b,e)-> 반복자 구간을 할당함 array의 i부터 j까지 temp에 할당
		sort(temp.begin(), temp.end()); // 정렬
		answer.push_back(temp[commands[i][2] - 1]); // k번째 수를 answer에 저장
	}


	return answer;
}