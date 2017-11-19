#include <iostream>
#include <stdlib.h>
using namespace std;

int n;
int nums[1000];

int cmp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

// ˼·��DFS����ȫ��ϣ�ͬʱע���֦�������ظ����
int findall(int tnums[], int index, long sum, long multi) {
	int count = 0;
	for (int i = index; i < n; i++) {
		sum += tnums[i];
		multi *= tnums[i];
		if (sum > multi)
			count += 1 + findall(tnums, i + 1, sum, multi);
		else if (tnums[i] == 1)
			count += findall(tnums, i + 1, sum, multi);
		else
			break;
		sum -= tnums[i];
		multi /= tnums[i];
		// ������ȵ�Ԫ�أ������ظ����
		while (i < n - 1 && tnums[i] == tnums[i + 1])
			i++;
	}
	return count;
}

int main(int argc, char* argv[])
{
	cin >> n;

	for (int i = 0; i<n; i++)
		cin >> nums[i];

	// ��С��������
	qsort(nums, n, sizeof(int), cmp);
	cout << findall(nums, 0, 0, 1) << endl;

	return 0;
}