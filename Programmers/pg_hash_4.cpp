#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, vector<pair<int, int>>> um;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first) 
		return a.second < b.second; // ���Ƚ���� ���� ���� ������ȣ ������	
	else 
		return a.first > b.first;  // ���Ƚ�� ��������	
}

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	for (int i = 0; i < genres.size(); i++) 
		um[genres[i]].push_back(pair<int, int>(plays[i], i));		

	unordered_map<string, vector<pair<int, int>>>::iterator it = um.begin();
	vector<pair<int, vector<int>>> v(um.size()); 
	// vector<pair<int, vector<int>>> v; ������ ������ ���� �ſ� �� �� �� �� �� �� �� �� Ÿ �� *****
	int i = 0;
	for (it; it != um.end(); it++) {
		vector<pair<int, int>> temp = it->second;
		
		sort(temp.begin(), temp.end(), compare);
		for (int j = 0; j < temp.size(); j++) {
			v[i].first += temp[j].first;
			v[i].second.push_back(temp[j].second);
		}	
		i++;
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.size() && j < 2; j++) {
			answer.push_back(v[i].second[j]);
			//printf("%d\n", v[i].second[j]);
		}		
	}
	
	return answer;
}

int main() {
	vector<string> v = { "classic","pop","classic","classic","pop" };
	
	vector<int> plays = { 500,600,150,800,2500 };
	vector<int> ans;

	ans = solution(v, plays);

	return 0;
}