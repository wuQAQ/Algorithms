#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int A[105];
bool appearIdx[105];
int missIdx[15];
int missNum[15];
int misscnt = 0;
int smaller[105][105];
int larger[105][105];

int calc_orderedPairs(int *num, int n);

int main() 
{
	int n, k;
	cin >> n >> k;

	if (k > n * (n - 1) / 2) {
		cout << 0;
		return 0;
	}

	// ��¼û�г��ֵ����ֵ�λ��
	for (int i = 0; i<n; i++) {
		cin >> A[i];
		if (!A[i])
			missIdx[misscnt++] = i;
		else 
			appearIdx[A[i]] = 1;
	}

	// ��¼û�г��ֵ����ֵĴ�С
	misscnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!appearIdx[i]) {
			missNum[misscnt++] = i;
		}
	}

	//��ȡ��֪�����ж�
	int given = calc_orderedPairs(A, n);
	if (given > k) {
		cout << 0;
		return 0;
	}

	// ����ÿ���ո��������ӵ����ж�
	for (int i = 0; i < misscnt; ++i) {
		int small = 0, large = 0;
		for (int j = 0; j < n; j++) {
			if (!A[j]) {
				smaller[j][missNum[i]] = small;
			}
			else if (A[j] < missNum[i])
				++small;
		}
		for (int j = n - 1; j >= 0; --j) {
			if (!A[j]) {
				larger[j][missNum[i]] = large;
			}
			else if (A[j] > missNum[i])++large;
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; ++j)
			cout << larger[i][j] << " ";
		cout << endl;
	}
*/
	int ans = 0;
	//not given
	do {
		// ��ȡ��ʧ�ַ����жԵĴ�С
		int inner = calc_orderedPairs(missNum, misscnt);
		for (int i = 0; i < misscnt; ++i) {
			inner += smaller[missIdx[i]][missNum[i]];
			inner += larger[missIdx[i]][missNum[i]];
		}
		if (inner + given == k) ++ans;
	} while (next_permutation(missNum, missNum + misscnt));

	cout << ans;
	return 0;
}

// ������֪���е����жԵ�����
int calc_orderedPairs(int *num, int n) {
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (num[i]) {
			for (int j = 0; j < i; j++) {
				if (num[j] && num[j] < num[i]) {
					++ans;
				}
			}
		}
	}
	return ans;
}