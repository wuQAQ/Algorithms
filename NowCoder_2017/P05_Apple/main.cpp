#include <iostream>
#include <string>	

using namespace std;

int main(void)
{
	int n;
	int *apple;
	long sum = 0;
	int maxPositive = 0;
	int maxNegative = 0;

	cin >> n;

	apple = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		sum += tmp;
		apple[i] = tmp;
	}
	sum /= n;
	for (int i = 0; i < n; i++)
	{
		apple[i] -= sum;
		if (apple[i] % 2 != 0)
		{
			cout << -1;
			return 0;
		}
		if (apple[i] > 0)
			maxPositive += apple[i];
		else
			maxNegative += apple[i];
	}
	
	if ((maxPositive + maxNegative) != 0)
		cout << -1;
	else
		cout << maxPositive / 2;

	return 0;
}