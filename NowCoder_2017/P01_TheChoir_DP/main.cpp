#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 50
const long long minn = -1e17;

struct DP {
	long long mins;
	long long maxs;
}dp[MAXN][10];

void GetMaxValue(int a[], int n, int k, int d);

int main() 
{
	int n;
	int a[MAXN];
	int k, d;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> k >> d;

	GetMaxValue(a, n, k, d);

	return 0;
}

void GetMaxValue(int a[], int n, int k, int d)
{
	long long res = minn;

	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i) 
		dp[i][0].mins = dp[i][0].maxs = a[i];

	for (int i = 0; i < n; ++i) {
		for (int ki = 1; ki < k; ++ki) {
			int j = i - d;
			if (j < 0) 
				j = 0;
			for (; j < i; ++j) {
				dp[i][ki].mins = min(dp[i][ki].mins, min(dp[j][ki - 1].mins * a[i], dp[j][ki - 1].maxs * a[i]));
				dp[i][ki].maxs = max(dp[i][ki].maxs, max(dp[j][ki - 1].mins * a[i], dp[j][ki - 1].maxs * a[i]));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		res = max(res, dp[i][k-1].maxs);
	}

	cout << res;
}