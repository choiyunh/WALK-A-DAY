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
	// �ﰢ���� ���� ũ���� ����������
	// ���������� ���� �� ũ�� ���� ���
	// vector<vector<int>> arr(6,vector<int>(5)) -> arr[6][5]
	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
	
	// �����
	int i = 1;
	dp[0][0] = (triangle[0][0]);
	for (i = 1; i < triangle.size(); i++) {
		// �� ���� �� ���� �θ��� ���� �ڽŰ� ���ؼ� �����ϰ�
		// ���̿� ���ִ� ������ �� �θ� �� ū���� ���ؼ� ����
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) // ���� ��
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j < i) // ���հ�
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			else // �� ��
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
		}
	}

	// ������ ������ �ִ밪 answer
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