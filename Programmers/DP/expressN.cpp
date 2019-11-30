#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// n은 9이하이기 때문에 최대 NNNNNNNNN
// num
int get(int num){
	int temp = 10;
	for (int i = 0; i < 9; i++) {
		if (num / 10 == 0) return temp;
		else temp * 10;
	}
}

int solution(int N, int number) {
	int answer = 0;
	vector<int> dp[9];

	if (number == N)
		return 1;

	dp[1].push_back(N);
	for (int i = 2; i < 9; i++) {
		// dp[i-1][0]에 10 곱하고 N더하면 숫자 붙임
		if ((10 * dp[i - 1][0]) + N == number) return i;      //숫자 붙여서 만들기
		else dp[i].push_back((10 * dp[i - 1][0]) + N);

		for (int j = 1; j < i; j++)    //연산 갯수
		{
			for (int k = 0; k < dp[j].size(); k++)
			{
				for (int p = 0; p < dp[i - j].size(); p++)
				{
					if (dp[j][k] * dp[i - j][p] == number) return i;
					dp[i].push_back(dp[j][k] * dp[i - j][p]);

					if (dp[j][k] + dp[i - j][p] == number) return i;
					dp[i].push_back(dp[j][k] + dp[i - j][p]);

					if (dp[j][k] - dp[i - j][p] == number) return i;
					dp[i].push_back(dp[j][k] - dp[i - j][p]);
					if (dp[i - j][p] != 0) {  //0으로 못나눔
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