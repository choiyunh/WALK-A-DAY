#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	vector<vector<int>> dp(n, vector<int>(m, 0)); // 해당 지점에 최단거리로 올 수 있는 길의 수
	
	// 물에 잠긴지점은 -1
	for (int i = 0; i < puddles.size(); i++)
		dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
	
	// 첫 번째 행만 왼쪽 검사해서 더해주고
	// 두 번째부터는 위,왼쪽 검사해서 물 잠긴 지점 아니면 더해서 저장.
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 물에 잠긴 지점은 패스
			if (dp[i][j] == -1) continue; 
			
			// 위쪽이 물에 잠긴 지점이 아니면
			if (i - 1 >= 0 && dp[i - 1][j] != -1)
				dp[i][j] += dp[i - 1][j] % 1000000007;

			// 왼쪽이 물에 잠긴 지점이 아니면
			if (j - 1 >= 0 && dp[i][j - 1] != -1)
				dp[i][j] += dp[i][j - 1] % 1000000007;			
		}
	}

	// 여기서 한 번 더 나머지연산 해줘야 효율성 통과 ;;; 왜 ?
	answer = dp[n - 1][m - 1] % 1000000007;
	return answer;
}

int main() {
	int m = 4;
	int n = 3;
	vector<vector<int>> p = { {2,2} };

	printf("%d\n", solution(m, n, p));

	return 0;
}