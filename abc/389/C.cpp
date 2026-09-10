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
ll q, d, idx;
ll quei[N * 3], quel[N * 3], head, tail;
int main() {
	rd.seed((ull)time(0));
	std::cin >> q;
	while (q --) {
		ll op, l;
		std::cin >> op;
		if (op == 1) {
			std::cin >> l;
			quei[tail] = idx, idx += l;
			quel[tail ++] = l;
		} else if (op == 2) {
			d += quel[head];
			head ++;
		} else if (op == 3) {
			std::cin >> l;
			std::cout << quei[head + l - 1] - d << std::endl;
		}
	}
	return 0;
}