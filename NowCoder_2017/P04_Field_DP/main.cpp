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
	// j1, j2, j3 ��ʾ����3��������ö�����е����
	for (int j1 = 1; j1 <= m - 3; j1++) {
		for (int j2 = j1 + 1; j2 <= m - 2; j2++) {
			for (int j3 = j2 + 1; j3 <= m - 1; j3++) {
				int peri = 0, cnt = 0;
				for (int i = 1; i <= n; i++) {
					// ȡ�м�4����Ԥ�����Сֵ���бȽ�
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
	// ������ش�С
	cin >> n >> m;

	// ��ȡ��صļ�ֵ
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++)
			Data[i][j] = temp[j - 1] - '0';
	}

	// ͳ��data[i][j]���Ͻǵ��ܼ�ֵ
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
		// �����м�ֵ����ΪԤ�����ֵ���ö��ֵķ������˱ƽ�
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