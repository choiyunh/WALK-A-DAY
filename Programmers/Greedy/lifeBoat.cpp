#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	
	// people�� �������� ���� ��
	// limit - people[0]�� 40���� ������ answer++, erase
	// 40���� ũ�� Ž�� �� ���� erase , answer++
	// people�� �� ������ �ݺ�
	sort(people.begin(), people.end(), greater<int>());

	int i = 0;
	// erase���ϱ� ȿ���� X
	// i���� ��Ÿ�� ������� 0���� ǥ��
	while (i<people.size()) {
		// 40���� �۰ų� 240���� ũ�� ��� X (�̹� ���� ��� 0)
		if (people[i] < 40 || people[i]>240) {
			i++;
			continue;
		}
		// max�� ���� ���� �迡 Ż �� �ִ� ������ �ִ밪
		int max = limit - people[i];
		// ����� �ּ� �����԰� 40�̱� ������
		// ������ ȥ�� ���ߴ�
		if (max < 40) {
			answer++;
			people[i++] = 0;
		}
		// �� �¿� �� ������
		else {
			int flag = 0;
			for (size_t j = i + 1; j < people.size(); j++) {
				// people[j]�� 0�ΰ��� �̹� �տ��� ���� ������ ��
				// max���� ������ ����� �ִٸ�
				if (people[j] <= max && people[j] >= 40) {
					people[i++] = 0;
					people[j] = 0;
					flag = 1;
					answer++;
					break;
				}
			}
			// �¿� �� �ִ� ������ ����� ���ٸ� ȥ�ڰ�
			if (flag == 0) {
				people[i++] = 0;
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> p = { 10,20,30,50 };
	int l = 100;

	printf("%d\n", solution(p, l));
	return 0;
}