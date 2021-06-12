#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;
	vector<int> tmp;

	std::cin >> x >> y >> w >> h;

	tmp.push_back(x);
	tmp.push_back(y);
	tmp.push_back(w - x);
	tmp.push_back(h - y);

	sort(tmp.begin(), tmp.end());

	cout << tmp[0] << endl;

	return 0;
}