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
#include <unordered_set>
//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class T>
using pt = std::pair<T, T>;
using namespace std;

struct hoba //sub-arrays
{
	hoba(int n)
	{
		sq.reserve(n);
	}
	int l, r;
	vector<pt<int>>sq;
};

void build(vector<hoba> &a)// sub-arrays
{
	int n;
	cin >> n;
	int q = ceil(sqrt(n));
	a.resize(q, hoba(q));
	int in;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		a[i / q].sq.push_back({ in,i });
	}
	if (a.back().sq.size() == 0)
		a.pop_back();
	for (int i = 0; i < a.size(); i++)
	{
		a[i].l = i * q;
		a[i].r = i * q + q - 1;
	}
	a.back().r = n - 1;
}

struct hoba2 //full array 
{
	int x, l;
};

void build(vector<hoba2> &a)// full array
{
	int n;
	cin >> n;
	int sq = ceil(sqrt(n));
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x;
		a[i].l = i / sq * sq;
	}
}

struct hoba3 //graph
{
	int x;
	bool isheavy = false;
	vector<int> ed, heavy;
	hoba3() { ed.reserve(210); heavy.reserve(155); }
};

void build(vector<hoba3> &a, vector<int> &heavy)// graph (heavy-light-node)
{						// heavy node no more than sqrt(n)
	int n, m, i1, i2;			// if node is light, then we can do bfs
	cin >> n >> m;				// else we can update nearest heavy edges
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x;
	}
	int sq = ceil(sqrt(n)); // 1e3?
	heavy.reserve(sq);
	for (int i = 0; i < m; i++)
	{
		cin >> i1 >> i2;
		//i1--; i2--;
		a[i1].ed.push_back(i2);
		a[i2].ed.push_back(i1);
		if (a[i1].ed.size() > sq && !a[i1].isheavy)
		{
			heavy.push_back(i1);
			a[i2].heavy.push_back(i1);
			a[i1].isheavy = true;
		}
		if (a[i2].ed.size() > sq && !a[i2].isheavy)
		{
			heavy.push_back(i2);
			a[i1].heavy.push_back(i2);
			a[i2].isheavy = true;
		}
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

	return 0;
}
