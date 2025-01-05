#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <random>
#include <bitset>
#include <tuple>
#include <iterator>
#include <stack>
#include <unordered_map>

using ll = long long;
using ull = unsigned long long;

typedef std::pair<int, int> PII;

std::mt19937_64 rd(114514);

const int N = 1010;

int mvx[4] = {1, -1, 0, 0}, mvy[4] = {0, 0, 1, -1};

inline int read() {
	int s = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}
void print(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
char grid[N][N];
ll h, w;
ll dist[N][N];
struct tup {
	ll x, y;
	ll flag;
};
int main() {
	rd.seed((ull)time(0));
	memset(dist, 0x3f, sizeof dist);
	scanf("%lld%lld", &h, &w);
	for (int i = 1; i <= h; i ++) {
		scanf("%s", grid[i] + 1);
	}

	ll sx = -1, sy = -1;
	for (int i = 1; i <= h; i ++) {
		for (int j = 1; j <= w; j ++) {
			if (grid[i][j] == 'S') {
				sx = i, sy = j;
				break;
			}
		}
		if (sx != -1) break;
	}

	std::queue<tup> q;
	q.push({sx, sy, -1});
	dist[sx][sy] = 0;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		if (t.flag == -1) {
			for (int i = 0; i < 2; i ++) {
				ll tx = t.x + mvx[i], ty = t.y + mvy[i];
				if (tx < 1 || tx > h || ty < 1 || ty > w || grid[tx][ty] == '#') {
					continue;
				}
				if (dist[tx][ty] > dist[t.x][t.y] + 1) {
					dist[tx][ty] = dist[t.x][t.y] + 1;
					q.push({tx, ty, 2});
				}
			}
			for (int i = 2; i < 4; i ++) {
				ll tx = t.x + mvx[i], ty = t.y + mvy[i];
				if (tx < 1 || tx > h || ty < 1 || ty > w || grid[tx][ty] == '#') {
					continue;
				}
				if (dist[tx][ty] > dist[t.x][t.y] + 1) {
					dist[tx][ty] = dist[t.x][t.y] + 1;
					q.push({tx, ty, 1});
				}

			}
		} else if (t.flag == 1) {
			for (int i = 0; i < 2; i ++) {
				ll tx = t.x + mvx[i], ty = t.y + mvy[i];
				if (tx < 1 || tx > h || ty < 1 || ty > w || grid[tx][ty] == '#') {
					continue;
				}
				if (dist[tx][ty] > dist[t.x][t.y] + 1) {
					dist[tx][ty] = dist[t.x][t.y] + 1;
					q.push({tx, ty, 2});
				}
			}
		} else if (t.flag == 2) {
			for (int i = 2; i < 4; i ++) {
				ll tx = t.x + mvx[i], ty = t.y + mvy[i];
				if (tx < 1 || tx > h || ty < 1 || ty > w || grid[tx][ty] == '#') {
					continue;
				}
				if (dist[tx][ty] > dist[t.x][t.y] + 1) {
					dist[tx][ty] = dist[t.x][t.y] + 1;
					q.push({tx, ty, 1});
				}

			}
		}
	}
	ll gx = -1, gy = -1;
	for (int i = 1; i <= h; i ++) {
		for (int j = 1; j <= w; j ++) {
			if (grid[i][j] == 'G') {
				gx = i, gy = j;
				break;
			}
		}
		if (gx != -1) break;
	}
	if (dist[gx][gy] == 0x3f3f3f3f3f3f3f3f) std::cout << -1;
	else std::cout << dist[gx][gy];
	return 0;
}