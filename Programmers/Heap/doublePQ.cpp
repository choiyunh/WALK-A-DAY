#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	vector<int> pq;

	while (!operations.empty()) {
		char com = operations[0][0];
		int data = atoi(operations[0].substr(2).c_str());
		
		if (com == 'I') {
			pq.push_back(data);
			sort(pq.begin(), pq.end(), greater<int>());
		}
		else if(com == 'D' && !pq.empty()){
			if (data == 1) 	pq.erase(pq.begin());
			else pq.erase(pq.begin() + (pq.size() - 1));
		}
		operations.erase(operations.begin());
	}

	if (pq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else if (pq.size() == 1)
		answer.push_back(pq.front());
	else {
		answer.push_back(pq.front());
		answer.push_back(pq.back());
	}
	return answer;
}

int main() {
	vector<string> s = { "I 16","I -5643","D -1","D 1","D 1","I 123","D -1" };

	printf("%d\n", solution(s)[0]);
	return 0;
}