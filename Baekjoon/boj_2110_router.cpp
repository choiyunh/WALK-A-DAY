#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int N, C; // ���� ����, ������ ����
	vector<int> house; // ���� ��ǥ
	cin >> N >> C;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(), house.end()); //��ǥ �������� ����

	int left = 1;
	int right = house[N - 1] - house[0]; // �ִ� �Ÿ�

	int mid;
	int cnt, ans;
	// �̺�Ž��
	while (left <= right) {
		mid = (left + right) / 2; // ���� ������ �͵� ������ �Ÿ�
		int start = house[0];
		cnt = 1;
		for (int i = 1; i < N; i++) {
			if ((house[i] - start) >= mid) {// house[i]�� ��ġ
				cnt++; // ������ ���� ����
				start = house[i];
			}
		}

		if (cnt >= C) {// �����⸦ C�� �̻� ��ġ �����ϸ� ������ ��������(midũ��)
			ans = mid;
			left = mid + 1;
		}
		else { // �ƴϸ� ������ ��������
			right = mid - 1;
		}
	}

	printf("%d\n", ans);


	return 0;
}