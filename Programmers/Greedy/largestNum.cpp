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
	// 첫 인덱스부터 자신과 다음 수 비교해서 작으면 삭제 후 k--;
	// 삭제하면 다시 첫 인덱스부터 반복 
	while (k > 0) {
		int i = 0;
		flag = false;
		for (i = 0; i < number.length() - 1; i++) {
			if (number[i] < number[i + 1]) { // 내가 다음 수보다 작으면 삭제
				number.erase(i, 1);
				k--;
				flag = true;
				break;
			}
		}
		// 다 검사했으나 k가 남았을 때 -> k가 남았는데 삭제할게 없다.
		// -> 끝에 작은 수가 있음. (ex "1010" )
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
