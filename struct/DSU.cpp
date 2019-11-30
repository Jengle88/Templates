//Goodbye stupid girls & Hello L0u1Za, Codeforces and my friends(nobody)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <utility>
#include <climits>
#include <functional>
#include <iomanip>
#include <stack>
#include <queue>
#include <type_traits>
#include <deque>
#include <unordered_map>
//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class T>
using pt = std::pair<T, T>;
using namespace std;

struct hoba
{
	int val;
	int min = 1e9, max = -1e9;
	int size = 1;
};

vector<hoba> a;
int findik(int x)
{
	if (a[x].val != x)
		a[x].val = findik(a[x].val);
	return a[x].val;
}

void unionchik(int x, int y)
{
	x = findik(x), y = findik(y);
	if (a[x].val == a[y].val)
		return;
	if (a[x].size > a[y].size)
		swap(x, y);
	a[x].val = y;
	a[y].size += a[x].size;
	a[y].min = min(a[y].min, a[x].min);
	a[y].max = max(a[y].max, a[x].max);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	//freopen("input.txt", "r", stdin);
	//freopen("input2.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	a.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		a[i].val = i;
		a[i].max = i;
		a[i].min = i;
	}
	string s;
	int i1, i2;
	while (cin >> s)
	{
		if (s == "union")
		{
			cin >> i1 >> i2;
			unionchik(i1, i2);
		}
		else
		{
			cin >> i1;
			int z = findik(i1);
			cout << a[z].min << ' ' << a[z].max << ' ' << a[z].size << '\n';
		}
	}
	return 0;
}