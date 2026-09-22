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
#include <unordered_set>

using ll = long long;
using ull = unsigned long long;

typedef std::pair<ll, ll> PLL;

std::mt19937_64 rd(114514);

const int N = 1e6  +10;
const ull MOD1 = 998244353, MOD2 = 1e9 + 7;

int mvx[4] = {1, -1, 0, 0}, mvy[4] = {0, 0, 1, -1};

inline ll read() {
	ll s = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}
void print(ll x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
ll n, s[N];
int main() {
	rd.seed((ull)time(0));
	n = read();
	for (int i = 1; i <= n; i ++) {
		s[i] = read();
	}

	ll step = 1;
	ll res = 0;
	while (step < n) {
		for (int i = 1; i <= n; i += step * 2) {
			ll max1 = -1, max2 = -1;
			for (int j = i; j - i + 1 <= step; j ++) {
				max1 = std::max(max1, s[j]);
			}
			for (int j = i + step; j - i + 1 <= step * 2; j ++) {
				max2 = std::max(max2, s[j]);
			}
			res += llabs(max1 - max2);
		}
		step *= 2;
	}

	std::cout << res;
	return 0;
}