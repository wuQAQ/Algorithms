#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

#define MAXN 50

int n, m;
int direction[MAXN][2];
int dcnt;
char ground[MAXN][MAXN];
int dis[MAXN][MAXN];

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) :x(_x), y(_y) {}
	Point go(int idx) {
		return Point(x + direction[idx][0], y + direction[idx][1]);
	}
	bool isOK() {
		return x >= 0 && y >= 0 && x < n && y < m && ground[x][y] == '.';
	}
};

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ground[i];
	}
	Point start;
	cin >> start.x >> start.y;
	cin >> dcnt;
	for (int i = 0; i < dcnt; i++) {
		cin >> direction[i][0] >> direction[i][1];
	}
	fill(dis[0], dis[MAXN-1] + MAXN, INT_MAX);
	dis[start.x][start.y] = 0;

	queue<Point> q;
	q.push(start);
	while (!q.empty()) {
		Point indexPoint = q.front(); q.pop();
		for (int i = 0; i < dcnt; ++i) {
			Point nextPoint = indexPoint.go(i);
			if (nextPoint.isOK()) {
				if (dis[nextPoint.x][nextPoint.y] > dis[indexPoint.x][indexPoint.y] + 1) {
					dis[nextPoint.x][nextPoint.y] = dis[indexPoint.x][indexPoint.y] + 1;
					q.push(nextPoint);
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] == '.') answer = max(answer, dis[i][j]);
		}
	}
	cout << (answer == INT_MAX ? -1 : answer);
	return 0;
}
