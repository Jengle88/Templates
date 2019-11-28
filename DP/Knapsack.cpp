//Goodbye stupid girls & Hello L0u1Za, Codeforces and my friends(nobody)
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

void recov(vector<vector<int>> &a, vector<int> &b, vector<int> &out)
{
	int i = a.size() - 1, j = a[0].size() - 1;
	while (i != 0)
	{
		if (a[i][j] > a[i - 1][j])
		{
			out.push_back(b[i]);
			j -= b[i];
		}
		i--;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;//things, need weight
	cin >> m >> n;
	vector<vector<int>> kn(n+1, vector<int>(m+1));
	vector<int> a(n+1), ans;//recovered answer
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j >= a[i] && j >= a[i] + kn[i - 1][j - a[i]])
				kn[i][j] = max(kn[i - 1][j], a[i] + kn[i - 1][j - a[i]]);
			else
				kn[i][j] = kn[i - 1][j];
		}
	}
	recov(kn, a,ans);// recover answer
	cout << kn[kn.size()-1][kn[0].size() - 1];//max size
	return 0;
}
