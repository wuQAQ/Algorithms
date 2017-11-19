#include <iostream>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

int main() {
	int n;
	int times = 4;
	int ans = 100001;

	cin >> n;

	for (int i = 1; i <= 300000; ++i) {
		int x = ((long long)(n)*times + times - 1) % mod;
		if (x == 0) {
			ans = (i + 1) / 3 + ((i + 1) % 3 ? 1 : 0);
			break;
		}
		times = times * 2 % mod;
	}

	cout << (ans > 100000 ? -1 : ans);
	return 0;
}