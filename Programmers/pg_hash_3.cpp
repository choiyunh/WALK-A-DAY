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
	answer = it++->second + 1;
	for (it; it != um.end(); it++) {
		answer *= it->second + 1;
	}
	answer -= 1;
	return answer;
}

int main() {
	vector<vector<string>> v = { {"yellow_hat","headgear"},{"blue_sunglasses","eyewear"},{"green_turban","headgear"} };

	printf("%d\n", solution(v));
	return 0;
}