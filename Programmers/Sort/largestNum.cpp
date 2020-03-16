#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) { // 내림차순 정렬하는데 a>b하면 1,10 중 10이 먼저옴
	return a + b > b + a;  // 큰 수를 만드려면 1이 먼저 오게 정렬해야하므로
}			       // a+b와 b+a중 큰 게 먼저. (1,6같은 수는 a>b 든 a+b>b+a든 6이 먼저오니까 무관) 
string solution(vector<int> numbers) {
	string answer;
	vector<string> temp;

	for (int i : numbers) { // number의 수를 string으로 변환하여 temp에 저장
		temp.push_back(to_string(i));
	}

	sort(temp.begin(), temp.end(), cmp); // 정렬

	if (temp[0] == "0") {  // 첫 글자가 0이면 예외처리
		answer += '0';
		return answer;
	}
	for (string s : temp) { // 정렬된 대로 수를 붙여서 answer만듬
		answer += s;
	}

	return answer;
}

int main() {

	vector<int> v = { 3, 30, 34, 5, 9 };
	vector<string> v2 = { "3","30","34","9","5"};
	//string s = solution(v);
	string a = "3";
	string b = "34";

	if (a > b)
		printf("%s\n", a.c_str());

	sort(v2.begin(), v2.end(), cmp);

	printf("%s\n", v2[4].c_str());
	return 0;
}
