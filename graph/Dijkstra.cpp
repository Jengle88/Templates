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

struct hoba
{
	int dist = 1e9;
	vector<pt<int>> ed;
};
vector<hoba> gr;

void djk(int st,int fin)
{
	priority_queue<pt<int>> q;
	q.push({ 0,st });
	gr[st].dist = 0;
	while (!q.empty())
	{
		int dist = q.top().first;
		int x = q.top().second;
		q.pop();
		for (int i = 0; i < gr[x].ed.size(); i++)
		{
			int u = gr[x].ed[i].first;
			if (gr[u].dist < dist)
				continue;
			if (gr[u].dist > gr[x].dist + gr[x].ed[i].second)
			{
				gr[u].dist = gr[x].dist + gr[x].ed[i].second;
				q.push({gr[u].dist, u});
			}
		}
	}
}

void example()
{
	int n, a, b, i1;
	cin >> n >> a >> b;
	gr.resize(n);
	/*	int m;//edges list
		cin >> m;
		int i2, i3, i4;
		for (int i = 0; i < m; i++)
		{
			cin >> i2 >> i3 >> i4;
			gr[i2-1].ed.push_back({ i3-1,i4 });
		}*/
	for (int i = 0; i < n; i++)//matrix
	{
		for (int j = 0; j < n; j++)
		{
			cin >> i1;
			if (i == j || i1 == -1)
				continue;
			else
				gr[i].ed.push_back({ j,i1 });
		}
	}
	djk(--a, --b);
	if (gr[b].dist == 1e9)
		cout << -1;
	else
		cout << gr[b].dist;
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
