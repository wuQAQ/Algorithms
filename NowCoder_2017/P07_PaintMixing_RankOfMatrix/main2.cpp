#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, x[55];
	int res = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i];

	for (int i = n - 1; i > 0; --i)
	{
		sort(x, x + i + 1);
		for (int j = i - 1; j >= 0; --j)
			if ((x[i] ^ x[j]) < x[j])
				x[j] ^= x[i];
	}

	for (res = 0; x[res] == 0; ++res);
	cout << n - res;
	return 0;
}