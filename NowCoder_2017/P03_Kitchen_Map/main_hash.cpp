#include<iostream>
#include<cstring>

using namespace std;
int res = 0;

struct Trie_node {
	bool flag;
	int id;
	Trie_node *next[27];
	Trie_node() {
		flag = false;
		id = 0;
		memset(next, 0, sizeof(next));
	}
}root;

int Hash(char *s) {
	Trie_node *p = &root;
	int len = 0;
	while (s[len] != '\0') {
		int index = s[len++] - 'A';
		if (!p->next[index])
			p->next[index] = new Trie_node;
		p = p->next[index];
	}
	if (!p->flag) {
		p->id = res++;
		p->flag = true;
	}
	return p->id;
}

int main() {
	char step[51];
	while (cin >> step) {
		Hash(step);
	}
	cout << res << endl;
	return 0;
}