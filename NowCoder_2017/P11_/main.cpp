#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int flag[3] = { 0, 0, 0 };
	string str;

	cin >> str;

	for (int i = 0; i < str.size() - 1; ++i) {
		if (str[i] < 'A' || str[i + 1] > 'Z')
			flag[0] = 1;
		if (str[i] == str[i + 1])
			flag[1] = 1;

		for (int j = i + 1; j < str.size(); ++j) {
			if (str[i] == str[j]){
				for (int k = i + 1; k < j; ++k) 
					for (int m = j + 1; m < str.size(); ++m)
						if (str[m] == str[k]) {
							flag[2] = 1;
							break;
						}
			}
		}	
	}

	if (str[str.size() - 1] < 'A' || str[str.size() - 1] > 'Z')
		flag[0] = 1;

	/*cout << flag[0] << flag[1] << flag[2] << endl;*/
	if (flag[0] + flag[1] + flag[2])
		cout << "Dislikes";
	else
		cout << "Likes";

	return 0;
}