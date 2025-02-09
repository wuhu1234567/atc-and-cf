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

const int N = 110;

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
int n;
int cnt[N][100010];
std::vector<int> G[N];
int len[N];
int main() {
	rd.seed((ull)time(0));
	std::cin >> n;
	for (int i = 1; i <= n; i ++) {
		int k = 0;
		std::cin >> k;
		len[i] = k;
		for (int j = 1; j <= k; j ++) {
			int x; 
			std::cin >> x;
			cnt[i][x] ++;
			G[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i ++) {
		std::sort(G[i].begin(), G[i].end());
		G[i].erase(std::unique(G[i].begin(), G[i].end()), G[i].end());
	}
	long double ans = 0.0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			long double tmp = 0.0;
			for (auto x : G[i]) {
				tmp += ((cnt[i][x] * 1.0L / (len[i] * 1.0L)) * (cnt[j][x] * 1.0L) / (len[j] * 1.0L));
			}
			if (tmp > ans) ans = tmp;
		}
	}
	printf("%.15Lf", ans);
	return 0;
}