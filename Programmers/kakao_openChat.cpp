#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> user;
	vector<pair<string, string>> event;

	for (string str : record) {
		int temp = str.find(' ');
		string command = str.substr(0, temp);
		string id = str.substr(temp + 1, str.find(' ', temp + 1) - (temp + 1));
		temp = str.find(' ', temp + 1);
		string name = str.substr(temp + 1);		

		if (command == "Enter") {
			user[id] = name;
			event.push_back(pair<string, string>(id, "님이 들어왔습니다."));
		}
		else if (command == "Leave") {
			event.push_back(pair<string, string>(id, "님이 나갔습니다."));
		}
		else {
			user[id] = name;
		}
	}

	for (int i = 0; i < event.size(); i++) {
		answer.push_back(user[event[i].first] + event[i].second);
	}
	
	return answer;
}

int main() {
	vector<string> r = { "Enter uid1234 Muzi","Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<string> ans = solution(r);

	for (string v : ans)
		printf("%s\n", v.c_str());

	return 0;
}