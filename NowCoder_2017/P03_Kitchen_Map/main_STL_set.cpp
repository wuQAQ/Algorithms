#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	set<string> myset;
	string str;
	string word;

	while (cin >> str)
	{
		myset.insert(str);
	}
	cout << myset.size() << endl;

	return 0;
}