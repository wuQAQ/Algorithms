#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> vec;

bool Lenths();
bool lexicographically();

int main() {
	string s;
	int n, i = 0;
	bool b1, b2;

	cin >> n;
	while (i < n) {
		cin >> s;
		vec.push_back(s);
		i++;
	}

	b1 = lexicographically();
	b2 = Lenths();

	if (b1 && b2)
		cout << "both";
	else if (b1 && !b2)
		cout << "lexicographically";
	else if (!b1 && b2)
		cout << "lengths";
	else
		cout << "none";


	return 0;
}

//°´ÕÕ×Ö·û´®´óÐ¡ÅÅÐò
bool Lenths() {
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].size() < vec[i - 1].size())
			return 0;
	}
	return 1;
}


//°´ÕÕ×ÖµäÐòÅÅÐò
bool lexicographically() {
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i - 1].compare(vec[i]) > 0)
			return 0;
	}
	return 1;
}