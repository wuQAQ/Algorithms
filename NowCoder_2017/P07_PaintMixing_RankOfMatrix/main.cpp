#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��������λ�ǵڼ�λ
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

		//endValue��cmpValueָ�����һ�����͵����ڶ�����
		int endValue = n - 1;
		int cmpValue = endValue - 1;
		//������ɫ���ϲ��л�ϵĿ��ܣ����ֻ��Ҫ������ɫ����ô���پ�Ҫ�������֣�����һ���ǲ����ܵõ�������ɫ�ġ�
		while (colors.size() > 2)
		{
			//ֻ�����λ��ͬ����ô���ǵ����λһ��������ȥ
			if (getHighPosition(colors[endValue]) == getHighPosition(colors[cmpValue]))
			{

				int temp = colors[endValue] ^ colors[cmpValue];
				//����������������ά����ɫû�У��ͼ��뵽colors��
				if (find(colors.begin(), colors.end(), temp) == colors.end())
				{
					colors.push_back(temp);
					sort(colors.begin(), colors.end());
					//��Ϊ�¼�����һ����������Ϊ����endValue��cmpValue����ָ������һ�͵����ڶ���������Ҫ++
					endValue++;
					cmpValue++;
				}
			}
			else
			{
				res++;
			}
			//ÿ�ж���һ�Σ��Ͱ����һ�����ӵ���ûʲô����
			colors.pop_back();
			endValue = cmpValue;
			cmpValue--;
		}
		cout << res + colors.size() << endl;

	}
}