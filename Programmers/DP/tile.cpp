#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	vector<long long> dp(N + 1);

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < N + 1; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	answer = (dp[N] * 2) + ((dp[N] + dp[N - 1]) * 2);
	
	return answer;
}

int main() {
	int n = 5;
	printf("%lld\n", solution(n));
	return 0;
}