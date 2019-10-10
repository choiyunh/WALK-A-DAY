#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, int> um;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	
	for (int i = 0; i < genres.size(); i++)
		um[genres[i]]++;


	unordered_map<string, int>::iterator it = um.begin();
	for (; it != um.end(); it++) {
		if (it->second >= 2) {

		}
	}
	return answer;
}

int main() {
	vector<string> v = { "classic","pop","claasic","classic","pop" };
	
	vector<int> plays,ans;

	ans = solution(v, plays);

	return 0;
}