#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b){
	if ((a + b) > (b + a)) return true;
	else return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> vs;

	for (int i = 0; i < numbers.size(); i++) {
		vs.push_back(to_string(numbers[i]));
	}

	sort(vs.begin(), vs.end(), cmp);

	for (int i = 0; i < vs.size() ; i++) {
		answer += vs[i];
	}

	return answer;
}

int main() {

	vector<int> v = { 3, 30, 34, 5, 9 };

	solution(v);

	return 0;
}
