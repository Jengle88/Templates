////Goodbye stupid girls & Hello L0u1Za, Codeforces and my friends(nobody)
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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	//freopen("input2.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	ll lim = log2(n)+2;
	vector<vector<ll>> dp(n, vector<ll>(lim));
	for (int i = 0; i < n; i++)//start
	{
		cin >> dp[i][0];
	}
	for (int k = 1; k < lim; k++)//build tabl
	{
		for (int i = 0; i < n; i++)
		{
			if (i + (1 << (k - 1)) < n)
			{
				int z = 1 << (k - 1);
				dp[i][k] = min(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
			}
		}
	}
	int q;
	cin >> q;
	while (q--)//print ans
	{
		int l, r;
		cin >> l >> r;
		l--; r--;
		if (l > r)
			swap(l, r);
		ll lg = (int)log2(r - l + 1);
		r++;
		cout << min(dp[l][lg], dp[r - (1 << lg)][lg]) << ' ';
	}
	return 0;
}
