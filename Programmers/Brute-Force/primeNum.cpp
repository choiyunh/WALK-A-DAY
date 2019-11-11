#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

bool checkNum(int i, string numbers);
vector<int> getPrime(int num);

int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>()); // 내림차순 정렬
	int tempNum = stoi(numbers);
	vector<int> temp = getPrime(tempNum);
	vector<int> pN;
	for (int i = 2; i <= tempNum; i++) {
		if (temp[i] != 0)
			pN.push_back(i);
	}

	for (int i = 0; i < pN.size(); i++) {
		if (checkNum(pN[i], numbers)) {
			answer++;
		}
	}

	return answer;
}

bool checkNum(int i, string numbers) {
	int flag = 0;
	// numbers 71 , i 11 일 때..
	while (i != 0) {
		int tmp = i % 10;
		flag = 0;
		for (int j = 0; j < numbers.size(); j++) {
			if (numbers[j] - '0' == tmp) {
				flag = 1;
				numbers.erase(j, 1);
			}
		}
		if (flag == 0)
			return false;
		i /= 10;
	}
	return true;
}

vector<int> getPrime(int num) {
	//int num = stoi(numbers);
	vector<int> temp(num + 1);

	// 입력받은 수 만큼 입력
	for (int i = 2; i <= num; i++) {
		temp[i] = i;
	}

	for (int i = 2; i <= num; i++) {  // 나누는 값 i
		for (int j = 2; j <= num; j++) {
			if (temp[j] != i && temp[j] % i == 0) {  // i를 제외한 모든 i의 배수 0
				temp[j] = 0; 
			}
		}
	}
	return temp;
}

int main() {
	string n = "011";

	printf("%d\n", solution(n));
	return 0;
}
