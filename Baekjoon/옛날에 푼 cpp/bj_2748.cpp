#include <iostream>

long long d[91] = { 0 };

long long dp(int x){
	if (x == 0) return d[x] = 0;
	if (x == 1) return d[x] = 1;
	if (d[x] != 0) return d[x];
	
	return d[x] = dp(x - 1) + dp(x - 2);
}


int main() {
	int n = 0;
	std::cin >> n;

	printf("%lld\n",dp(n));
}