#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	// 삼각형과 같은 크기의 이차원벡터
	// 이차원벡터 선언 시 크기 지정 방법
	// vector<vector<int>> arr(6,vector<int>(5)) -> arr[6][5]
	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
	
	// 꼭대기
	int i = 1;
	dp[0][0] = (triangle[0][0]);
	for (i = 1; i < triangle.size(); i++) {
		// 각 층의 맨 끝은 부모의 값과 자신값 더해서 저장하고
		// 사이에 껴있는 값들은 두 부모 중 큰값과 더해서 저장
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) // 왼쪽 끝
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j < i) // 사잇값
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			else // 끝 값
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
		}
	}

	// 마지막 층에서 최대값 answer
	answer = dp[i - 1][0];
	for (int j = 1; j < i; j++) {
		if (dp[i - 1][j] > answer)
			answer = dp[i - 1][j];
	}	
	
	return answer;
}

int main() {
	vector<vector<int>> t = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };
	
	printf("%d\n", solution(t));
	return 0;
}