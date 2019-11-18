#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	string temp = number;
	bool flag = false;
	// ù �ε������� �ڽŰ� ���� �� ���ؼ� ������ ���� �� k--;
	// �����ϸ� �ٽ� ù �ε������� �ݺ� 
	while (k > 0) {
		int i = 0;
		flag = false;
		for (i = 0; i < number.length() - 1; i++) {
			if (number[i] < number[i + 1]) { // ���� ���� ������ ������ ����
				number.erase(i, 1);
				k--;
				flag = true;
				break;
			}
		}
		// �� �˻������� k�� ������ �� -> k�� ���Ҵµ� �����Ұ� ����.
		// -> ���� ���� ���� ����. (ex "1010" )
		if (flag == false && k > 0) { 
			number.erase(number.end()-1);
			k--;
		}
	}	
	return number;
}

int main() {
	// "1010" 2
	// "1111" 2
	// "1924" 2
	// "4177252841" 4
	string n = "11001";
	int k = 2;

	string result = solution(n, k);
	printf("%s\n", result.c_str());
	return 0;
}
