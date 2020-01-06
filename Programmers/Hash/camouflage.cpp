#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
unordered_map<string, int> um;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	
	for (int i = 0; i < clothes.size(); i++) {
		um[clothes[i][1]]++;
	}

	unordered_map<string, int>::iterator it = um.begin();
	// 경우의 수 계산 시 각 종류별 개수 +1(안 입는 경우)
	answer = it++->second + 1;
	for (it; it != um.end(); it++) {
		answer *= it->second + 1;
	}
	// 모든 종류 안입는 경우 제외 -1
	answer -= 1;
	return answer;
}

int main() {
	vector<vector<string>> v = { {"yellow_hat","headgear"},{"blue_sunglasses","eyewear"},{"green_turban","headgear"} };

	printf("%d\n", solution(v));
	return 0;
}
