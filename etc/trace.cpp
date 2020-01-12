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
		cout << "-----모든 Trace 정보를 출력합니다. ------" << endl;
		for (int i = 0; i < count; i++) {
			cout << func[i] << ":" << str[i] << endl;
		}
	}
	else {
		cout << "----- " << p << "태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < count; i++) {
			if (func[i] == "f()")
				cout << func[i] << ":" << str[i] << endl;
		}
	}
}
void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램 시작합니다.");
	f();
	Trace::put("main()", "종료");
	Trace::print("f()");
	Trace::print();
}
