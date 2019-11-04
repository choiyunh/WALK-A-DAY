#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}
string solution(vector<int> numbers) {
	string answer;
	vector<string> temp;

	for (int i : numbers) {
		temp.push_back(to_string(i));
	}

	sort(temp.begin(), temp.end(), cmp);

	if (temp[0] == "0") {
		answer += '0';
		return answer;
	}
	for (string s : temp) {
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
