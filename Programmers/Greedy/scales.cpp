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
		// ���� ���� ���� ���� �� �ִ� �ִ�+1 ���� ũ�� break;
		if (weight[i] > max + 1)
			break;
		else
			max + weight[i];
	}
	// ���� �� ���� �ּڰ�
	answer = max + 1;
	return answer;
}

int main() {
	vector<int> w = { 3,1,6,2,7,30,1 };

	printf("%d\n", solution(w));
	return 0;
}