#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	regex r("([^A-Z]+|([A-Z])\\2|([A-Z])[A-Z]*([A-Z])[A-Z]*\\3[A-Z]*\\4)");
	string word;
	while (cin >> word) {
		if (regex_search(word, r)) {
			cout << "Dislikes\n";
		}
		else {
			cout << "Likes\n";
		}
	}

	return 0;
}