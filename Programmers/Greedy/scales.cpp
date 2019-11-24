#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;
	sort(weight.begin(), weight.end());

	int max = weight[0];
	for (int i = 0; i < weight.size()-1; i++) {
		// 다음 수가 지금 만들 수 있는 최댓값+1 보다 크면 break;
		if (weight[i] > max + 1)
			break;
		else
			max + weight[i];
	}
	// 만들 수 없는 최솟값
	answer = max + 1;
	return answer;
}

int main() {
	vector<int> w = { 3,1,6,2,7,30,1 };

	printf("%d\n", solution(w));
	return 0;
}