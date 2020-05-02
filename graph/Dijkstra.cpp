//Goodbye stupid girls & Hello L0u1Za, Codeforces and my friends(nobody)
#define _CRT_SECURE_NO_WARNINGS
#define inf 1e9
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
	int to;
	int len = 0;
};
struct hoba
{
	int dist = inf;
	vector<ed> a;
};
vector<hoba> gr;

void djk(int st)
{
	priority_queue<pt<int>> q;//len,to
	gr[st].dist = 0;
	q.push({ 0,st });
	while (!q.empty())
	{
		auto pr = q.top();//len, to
		q.pop();
		for (int i = 0; i < gr[pr.second].a.size(); i++)
		{
			auto pr2 = gr[pr.second].a[i];//to and len
			if (gr[pr2.to].dist > pr.first + pr2.len)
			{
				gr[pr2.to].dist = pr.first + pr2.len;
				q.push({ gr[pr2.to].dist,pr2.to });
			}
		}
	}
}


void example()
{
	int n, s, f;
	cin >> n >> s >> f;
	int i1;
	gr.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> i1;
			if (i == j)
				continue;
			if (i1 != -1)
			{
				gr[i].a.push_back({ j,i1 });
			}
		}
	}
	djk(s);
	if (gr[f].dist == inf)
		cout << -1;
	else
		cout << gr[f].dist;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	example();
	return 0;
}
