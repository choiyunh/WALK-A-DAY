// joystcik.cpp
// Greedy Algorithm
// Created by Choiyunh

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
	int answer = 0;
	// N�� �����ε� �ڷε� 13�� �̵�
	// N ������ ���� ���ĺ� N���Ĵ� ���� ���ĺ����� ã�ư��°� ����
	vector<char> alpha = { 'A','B','C','D','E','F','G','H','I','J','K','L', // �׳� �ƽ�Ű�ڵ�� �ϴ°� ���ҷ���
	   'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	vector<bool> check(name.length(), false); // �ش� ��ġ�� �ٲ���ϴ��� üũ
	int cus = 0; // Ŀ���� ��ġ
	int i = 1;
	int j = 0;
	int cnt = 0;

	for (int i = 0; i < check.size(); i++) {
		if (name[i] == 'A') {
			check[i] = true;
			cnt++;
		}
	}

	// ù ��° ��ġ ���ĺ����� �ٲٰ� ����
	if (!check[cus]) {
		for (j = 0; j < alpha.size(); j++) {
			if (name[cus] == alpha[j]) {
				if (name[cus] > 'N') {// N���� ū ���ĺ��� �ڷ� �̵�
					j = alpha.size() - j;
				}
				break;
			}
		}
		answer += j;
		check[cus] = true;
		cnt++;
	}

	i = 1;
	j = 0;
	while (cnt < name.length()) {
		int right, left;
		right = cus + i; // �������� i��ŭ�� �̵�
		left = cus - i; // �������� i��ŭ�� �̵�
		// ������ �Ѿ��
		if (right >= name.length())
			right -= name.length();
		if (left < 0)
			left += name.length();

		if (!check[right]) {
			answer += i;
			cus = right;
			i = 1; // Ŀ�� �̵��ϸ� �ٽ� �¿�� ��ĭ�� �˻��ؾ� �ǹǷ�
			for (j = 0; j < alpha.size(); j++) {
				if (name[cus] == alpha[j]) {
					if (name[cus] > 'N') {// N���� ū ���ĺ��� �ڷ� �̵�
						j = alpha.size() - j;
					}
					break;
				}
			}
			answer += j;
			check[cus] = true;
			cnt++;
			j = 0;
			continue;
		}
		else if (!check[left]) {
			answer += i;
			cus = left;
			i = 1;  // Ŀ�� �̵��ϸ� �ٽ� �¿�� ��ĭ�� �˻��ؾ� �ǹǷ�
			for (j = 0; j < alpha.size(); j++) {
				if (name[cus] == alpha[j]) {
					if (name[cus] > 'N') {// N���� ū ���ĺ��� �ڷ� �̵�
						j = alpha.size() - j;
					}
					break;
				}
			}
			answer += j;
			check[cus] = true;
			cnt++;
			j = 0;
			continue;
		}
		i++; // �� ��� ��ĭ�� �÷����� �˻�
	}
	return answer;
}

int main() {
	//string name = "AABAAAAAAABBB";
	//string name = "JAZ";
	//string name = "ABABAAAAAAABA";
	string name = "BBAABB";
	printf("%d\n", solution(name));

	return 0;
}