#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int solution(vector<int> money) {
	int answer = 0;
	vector<int> dp1(money.size()); // 첫 번째 집을 훔치는 경우

	dp1[0] = money[0];
	dp1[1] = money[0];
	dp2[0] = 0;
	dp2[1] = money[1];
	dp2[2] = money[1];

	
	answer = max(dp1[money.size() - 2], dp2[money.size() - 1]);
	return answer;
}

int main() {
	vector<int> m = { 1,2,3,1 };
	
	cout << solution(m);
	return 0;
}