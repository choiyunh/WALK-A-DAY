#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int N, int number) {
	int answer = 0;
	vector<int> dp[9];

	if (number == N)
		return 1;
	
	dp[1].push_back(N);
	for (int i = 2; i < 9; i++) {       // 최솟값이 8보다 크면 -1 return
		if ((dp[i - 1][0] * 10 + N == number)) return i;      // 숫자 붙이기(5,55,555)
		else dp[i].push_back((N * 10) + N);
		for (int j = 1; j < i; j++) {   // j 와 i-j
			for (int k = 0; k < dp[j].size(); k++) {
				for (int p = 0; p < dp[i - j].size(); p++) {
					if (dp[j][k] + dp[i - j][p] == number) return i;
					dp[i].push_back(dp[j][k] + dp[i - j][p]);

					if (dp[j][k] - dp[i - j][p] == number) return i;
					dp[i].push_back(dp[j][k] - dp[i - j][p]);

					if (dp[j][k] * dp[i - j][p] == number) return i;
					dp[i].push_back(dp[j][k] * dp[i - j][p]);

					if (dp[i - j][p] != 0) {  // 분모가 0이 아닐 때
						if (dp[j][k] / dp[i - j][p] == number) return i;
						else if (dp[j][k] / dp[i - j][p] == 0);
						else dp[i].push_back(dp[j][k] / dp[i - j][p]);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int N = 5;
	int number = 12;

	printf("%d\n", solution(N, number));
	return 0;
}