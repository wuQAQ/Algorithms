#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	vector<string> allWord;
	int flag[2] = { 1, 1 }; // 第一个表示长度，第二个表示字典

	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string tmp;
		getline(cin, tmp);
		allWord.push_back(tmp);
	}

	for (int i = 1; i < n; i++) {
		int tf = 1;
		if (allWord[i].size() < allWord[i - 1].size()) {
			flag[0] = 0;
		}
		int tmpn = min(allWord[i].size(), allWord[i - 1].size());
		for (int j = 0; j < tmpn; j++) {
			if (allWord[i].at(j) == allWord[i - 1].at(j))
				continue;
			else if (allWord[i].at(j) > allWord[i - 1].at(j)) {
				tf = 0;
				break;
			}
			else
				flag[1] = 0;
		}
		if (tf && allWord[i].size() < allWord[i - 1].size())
			flag[1] = 0;
	}

	int res = flag[0] + flag[1] * 10;
	if (flag[0] && flag[1])
		cout << "both";
	else if (flag[0] && !flag[1])
		cout << "lengths";
	else if (!flag[0] && flag[1])
		cout << "lexicographically";
	else
		cout << "none";
	
	return 0;
}