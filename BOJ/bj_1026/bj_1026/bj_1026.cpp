#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;

int getS(vector<int> A_, vector<int> B_) {
	int sum = 0;

	sort(A_.begin(), A_.end(), greater<int>()); // A를 내림차순
	sort(B_.begin(), B_.end()); // B를 오름차순

	for (int i = 0; i < N; i++)
		sum += A_[i] * B_[i];

	return sum;
}

int main() {

	int tmp;
	vector<int> A, B;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		B.push_back(tmp);
	}

	cout << getS(A, B) << endl;


	return 0;
}