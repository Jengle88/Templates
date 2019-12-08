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
#include <type_traits>
#include <climits>
#include <functional>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class T>
using pt = std::pair<T, T>;
using namespace std;
int logn, t;
vector<vector<int>> up;//matrix bin lifts 1,2,4...
vector<vector<int>> g;
vector<int> tin,tout;//time in and out

bool anc(int u, int v)//checker, ancestor or not?
{
	return tin[u] <= tin[v] && tin[v] < tout[u];
}

void dfs(int v = 0)//dfs with up and time
{
	for (int l = 1; l < logn; l++)
		up[v][l] = up[up[v][l - 1]][l - 1];
	tin[v] = t++;
	for (int u : g[v])
	{
		up[u][0] = v;
		dfs(u);
	}
	tout[v] = t;
}

int lca(int u, int v) //find lca
{
	if (anc(v, u)) return v;
	if (anc(u, v)) return u;
	for (int l = logn - 1; l >= 0; l--)
	{
		if (!anc(up[v][l], u))
			v = up[v][l];
	}
	return up[v][0];
}

void solve()//example
{

	int n, m, i1, i2;
	cin >> n >> m;
	logn = ceil(log2(n));
	up.resize(n, vector<int>(logn));
	g.resize(n);
	tin.resize(n); tout.resize(n);
	for (int i = 0; i < m; i++)
	{
		cin >> i1 >> i2;
		g[i1].push_back(i2);
	}
	dfs();
	int q;
	cin >> q;
	while (q--)
	{
		cin >> i1 >> i2;
		cout << lca(i1, i2) << ' ';
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
