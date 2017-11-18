#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//求该数最高位是第几位
int getHighPosition(int a) {
	int count = 0;
	while (a) {
		a >>= 1;
		count++;
	}
	return count;
}

int main() {

	int n;
	vector<int> colors;

	while (cin >> n)
	{
		int temp;
		int res = 0;
		int i = n;

		colors.clear();
		while (i--) {
			cin >> temp;
			colors.push_back(temp);
		}
		sort(colors.begin(), colors.end());

		//endValue和cmpValue指向最后一个数和倒数第二个数
		int endValue = n - 1;
		int cmpValue = endValue - 1;
		//两种颜色以上才有混合的可能，如果只需要两种颜色，那么最少就要购买两种，购买一种是不可能得到两种颜色的。
		while (colors.size() > 2)
		{
			//只有最高位相同，那么他们的最高位一定可以消去
			if (getHighPosition(colors[endValue]) == getHighPosition(colors[cmpValue]))
			{

				int temp = colors[endValue] ^ colors[cmpValue];
				//如果异或出来的这个低维的颜色没有，就加入到colors里
				if (find(colors.begin(), colors.end(), temp) == colors.end())
				{
					colors.push_back(temp);
					sort(colors.begin(), colors.end());
					//因为新加入了一个数，所以为了让endValue和cmpValue还是指向倒数第一和倒数第二个数，需要++
					endValue++;
					cmpValue++;
				}
			}
			else
			{
				res++;
			}
			//每判断完一次，就把最后一个数扔掉，没什么用了
			colors.pop_back();
			endValue = cmpValue;
			cmpValue--;
		}
		cout << res + colors.size() << endl;

	}
}