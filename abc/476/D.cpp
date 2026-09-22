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

const int N = 2e5 + 10;
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
ll n, m, k;
ll x, y;
ll a[N], b[N];
ll pre[N];

ll bs(ll l, ll r, ll x) {
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (pre[mid] <= x) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	return l;
}
int main() {
	rd.seed((ull)time(0));
	n = read(), m = read(), k = read();
	x = read(), y = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	for (int i = 1; i <= m; i ++) {
		b[i] = read();
	}

	std::sort(a + 1, a + 1 + n);
	std::sort(b + 1, b + 1 + m);

	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + a[i];
	}

	ll tot = x + y * k;
	ll now = 0;
	for (int i = 1; i <= n; i ++) {
		if (pre[i] > tot) {
			now = i - 1;
			break;
		}
	}
	if (pre[n] <= tot) now = n;

	ll res = now;
	ll cost = 0;
	for (int i = 1; i <= m; i ++) {
		cost += b[i];
		if (b[i] > y * k) break;
		y -= (b[i] % k == 0 ? b[i] / k : (b[i] / k + 1));
		// std::cout << "i: " << i << "\n";
		ll cnt = bs(0, n, tot - cost);
		res = std::max(res, i + cnt);
	}

	std::cout << res;
	return 0;
}