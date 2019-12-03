#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	vector<vector<int>> dp(n, vector<int>(m, 0)); // �ش� ������ �ִܰŸ��� �� �� �ִ� ���� ��
	
	// ���� ��������� -1
	for (int i = 0; i < puddles.size(); i++)
		dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
	
	// ù ��° �ุ ���� �˻��ؼ� �����ְ�
	// �� ��°���ʹ� ��,���� �˻��ؼ� �� ��� ���� �ƴϸ� ���ؼ� ����.
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ��� ������ �н�
			if (dp[i][j] == -1) continue; 
			
			// ������ ���� ��� ������ �ƴϸ�
			if (i - 1 >= 0 && dp[i - 1][j] != -1)
				dp[i][j] += dp[i - 1][j] % 1000000007;

			// ������ ���� ��� ������ �ƴϸ�
			if (j - 1 >= 0 && dp[i][j - 1] != -1)
				dp[i][j] += dp[i][j - 1] % 1000000007;			
		}
	}

	// ���⼭ �� �� �� ���������� ����� ȿ���� ��� ;;; �� ?
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