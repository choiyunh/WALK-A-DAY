#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	// 오름차순 정렬
	sort(phone_book.begin(), phone_book.end());
	
	// 오름차순 정렬돼있으므로 i와 i+1만 비교해보면 됨
	// 같은게 있으면 접두어
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
			answer = false;
	}
	return answer;
}

int main() {
	vector<string> pb = { "119","97674223","1195524421" };

	if (solution(pb))
		printf("true\n");
	else
		printf("false\n");
	return 0;
}