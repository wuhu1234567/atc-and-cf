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

using ll = unsigned long long;

typedef std::pair<int, int> PII;

std::mt19937_64 rd(114514);

const int N = 11;

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
ll quickPow (ll x, ll p) {
	ll res = 1;
	while (p > 0) {
		if (p & 1) res *= x;
		x *= x;
		p >>= 1;
	}

	return res;
}
int main() {
	// rd.seed((ull)time(0));
	ll sum = 0;
	for (ll i = 1; i <= 6; i ++) {
		sum += quickPow(i, 17ULL);
	}
	sum += quickPow(6ULL, 17ULL);
	std::cout << sum;
	return 0;
}