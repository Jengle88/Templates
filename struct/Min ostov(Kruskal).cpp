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


struct ed
{
	int a, b;// a->b
	int w;	 // weight
};

struct snmachka //DSU
{
	int val,size; //root,size set

};
vector<snmachka> mnoj;//set our edges

int findik(int x)
{
	if (mnoj[x].val != x)
		mnoj[x].val = findik(mnoj[x].val);
	return mnoj[x].val;
}

void unionchik(int x,int y)
{
	x = findik(x), y = findik(y);
	if (mnoj[x].val == mnoj[y].val)
		return;
	if (mnoj[x].size > mnoj[y].size)
		swap(x, y);
	mnoj[x].val = y;
	mnoj[y].size += mnoj[x].size;
}

bool good(int x, int y)//no cycle
{
	return findik(x) != findik(y);
}

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
	int n, m;
	cin >> n >> m;
	vector<ed> a;
	mnoj.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		mnoj[i].val = i; //start root
	}
	a.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].w;
	}
	sort(a.begin(), a.end(), [](ed a, ed b) {return a.w < b.w; }); //sort by weight
	ll sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (good(a[i].a, a[i].b)) // if a.root != b.root -> no cycle in set with (a,b)
		{
			sum += a[i].w;
			unionchik(a[i].a, a[i].b);
		}
	}
	cout << sum;
	return 0;
}
