#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 75 + 5;
int n, m;
int Data[maxn][maxn], sum[maxn][maxn];

int GetArea(int x1, int y1, int x2, int y2) {
	return (sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1]);
}

bool Judge(int mid) {
	// j1, j2, j3 表示纵切3刀，暴力枚举纵切的情况
	for (int j1 = 1; j1 <= m - 3; j1++) {
		for (int j2 = j1 + 1; j2 <= m - 2; j2++) {
			for (int j3 = j2 + 1; j3 <= m - 1; j3++) {
				int peri = 0, cnt = 0;
				for (int i = 1; i <= n; i++) {
					// 取中间4块与预测的最小值进行比较
					int cub1 = GetArea(peri, 0, i, j1);
					int cub2 = GetArea(peri, j1, i, j2);
					int cub3 = GetArea(peri, j2, i, j3);
					int cub4 = GetArea(peri, j3, i, m);
					if (cub1 >= mid && cub2 >= mid && cub3 >= mid && cub4 >= mid) {
						peri = i;
						cnt++;
					}
				}
				if (cnt >= 4) return true;
			}
		}

	}
	return false;
}

int main() {
	// 输入田地大小
	cin >> n >> m;

	// 获取田地的价值
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++)
			Data[i][j] = temp[j - 1] - '0';
	}

	// 统计data[i][j]左上角的总价值
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + Data[i][j];
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << sum[i][j] << " ";
		cout << endl;
	}*/

	int low = 0, high = sum[n][m], mid, ans;
	while (low <= high) {
		// 计算中间值，作为预测最低值，用二分的方法两端逼近
		mid = (low + high) >> 1;
		/*cout << mid << " " << low << " " << high << endl;*/
		if (Judge(mid)) {
			low = mid + 1;
			ans = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << endl;

	return 0;
}