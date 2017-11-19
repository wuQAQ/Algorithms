#include <iostream>
#include <map>
#include <queue>

using namespace std;
const long long mod = 1000000007;

struct node {
	long long x, step;
	node(long long x, long long step) :x(x), step(step) {}
};

int main() {
	long long x;
	while (scanf("%lld", &x) != EOF) {
		queue<node> Q;
		map<long long, int> book;
		Q.push(node(x, 0)), book[x] = 1;
		long long res = -1;
		while (!Q.empty()) {
			node head = Q.front(); Q.pop();
			if (head.x%mod == 0) {
				res = head.step;
				break;
			}
			if (head.step>100000) break;
			long long x1 = (4 * head.x + 3) % mod, x2 = (8 * head.x + 7) % mod;
			if (book.count(x1) == 0) {
				book[x1] = 1;
				Q.push(node(x1, head.step + 1));
			}
			if (book.count(x2) == 0) {
				book[x2] = 1;
				Q.push(node(x2, head.step + 1));
			}
		}
		printf("%lld\n", res);
	}
}//直接bfs就可以啦~