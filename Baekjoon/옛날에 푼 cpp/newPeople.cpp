#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int N;
pair<int, int> employee[MAX];

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0); //����ӵ� ���

	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++){

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> employee[i].first >> employee[i].second;
			   
		sort(employee, employee + N);
		
		int result = 1; //ù ��° ����� ������ ����(�����ɻ� ���� 1��)
		int interviewRank = employee[0].second; //ù ��° ����� ���ͺ� �ɻ� ����

		for (int i = 1; i < N; i++)	{
			//������ ���ͺ� �ɻ� �������� ���� ������ ��� ä��
			if (employee[i].second < interviewRank)	{
				result++;
				//���ͺ� �ɻ� ���� ������Ʈ
				interviewRank = employee[i].second;
			}
		}
		cout << result << "\n";
	}

	return 0;

}