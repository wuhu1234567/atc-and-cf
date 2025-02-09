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

const int N = 3e5 + 10;

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
ll n;
ll look[N];
ll wd[N];
ll per[N];
int main() {
	rd.seed((ull)time(0));
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++) {
		ll x;
		std::cin >> x;
		look[i] = x;
	}
	for (int i = 1; i <= n; i ++) {
		ll x;
		std::cin >> x;
		wd[i] = x;
		per[x] = i;
	}
	for (int i = 1; i <= n; i ++) {
		std::cout << wd[look[per[i]]] << " ";
	}
	return 0;
}