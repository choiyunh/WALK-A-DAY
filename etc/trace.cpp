#include <iostream>
#include <string>
using namespace std;

class Trace {
public:
	static string func[100];
	static string str[100];
	static int count;
	static void put(string f, string s);
	static void print(string p);
};

int Trace::count = 0;
string Trace::func[100];
string Trace::str[100];

void Trace::put(string f, string s) {
	func[count] = f;
	str[count] = s;
	count++;
}

void Trace::print(string p = "") {
	if (p == "") {
		cout << "-----��� Trace ������ ����մϴ�. ------" << endl;
		for (int i = 0; i < count; i++) {
			cout << func[i] << ":" << str[i] << endl;
		}
	}
	else {
		cout << "----- " << p << "�±��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < count; i++) {
			if (func[i] == "f()")
				cout << func[i] << ":" << str[i] << endl;
		}
	}
}

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}

int main() {
	Trace::put("main()", "���α׷� �����մϴ�.");
	f();
	Trace::put("main()", "����");
	Trace::print("f()");
	Trace::print();
}