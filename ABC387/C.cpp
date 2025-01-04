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

const int N = 111;

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
std::string L, R;
ll quickPow (ll x, ll p) {
	ll res = 1;
	while (p > 0) {
		if (p & 1) res *= x;
		x *= x;
		p >>= 1;
	}

	return res;
}
ll call(std::string x) {
	ll len = x.length(), ans = 0;
	ll now = x[0] - '0';
	for (int i = 1; i < now; i ++) {
		ans += quickPow(i, len - 1);
	}
	// if (x == "21") std::cout << "ans1: " << ans << std::endl;
	for (int i = 1; i < len; i ++) {
		ll tmp = (ll)(x[i] - '0');
		if (tmp >= now) {
			ans += now * quickPow(now, len - i - 1LL);
			break;
		} else {
			if (i == len - 1) ans += tmp + 1;
			else ans += tmp * quickPow(now, len - i - 1LL);
		}
	}
	return ans == 0 ? 1 : ans;
}
bool check(std::string x);
ll calr(std::string x) {
	ll sum = 0;
	for (int i = 1; i <= 9; i ++) {
		sum += quickPow(i, x.length() - 1LL);
	}
	if (check(x)) sum ++;
	return sum - call(x);
}
bool check(std::string x) {
	char now = x[0];
	for (int i = 1; i < x.length(); i ++) {
		if (now <= x[i]) return false;
	}
	return true;
}
int main() {
	rd.seed((ull)time(0));
	std::cin >> L >> R;
	ll ans = 0;
	if (L.length() != R.length()) {
		ans = calr(L) + call(R);
		for (int i = L.length() + 1; i < R.length(); i ++) {
			std::string tmp = "";
			for (int j = 0; j < i; j ++) {
				tmp += '9';
			}
			ans += call(tmp);
		}
		// std::cout << call(R) << " " << calr(L) << std::endl;
	} else {
		ans = call(R) - call(L);
		if (check(L)) ans ++;
		// std::cout << call(R) << " " << call(L) << std::endl;
	}
	std::cout << ans;
	return 0;
}