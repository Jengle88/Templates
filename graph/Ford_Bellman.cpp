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
	ll to, len;
};

struct vert
{
	ll dist = inf;
	vector<ed> a;
};
vector<vert> gr;

void ford_belm(int st)
{
	gr[st].dist = 0;
	for (int i = 1; i < gr.size(); i++)
	{
		for (int j = 1; j < gr.size(); j++)	  //for all edges each time
		{					  //for all edges each time
			for (auto val : gr[j].a)          //for all edges each time
			{
				if(gr[j].dist != inf)//if not infinity, then decrease
					gr[val.to].dist = min(gr[val.to].dist, gr[j].dist + val.len);
			}
		}
	}
}

void example()
{
	int n, m;
	cin >> n >> m;
	gr.resize(n + 1);
	int i1, i2, w;
	for (int i = 0; i < m; i++)
	{
		cin >> i1 >> i2 >> w;
		gr[i1].a.push_back({ i2,w });
		//gr[i2].a.push_back({ i1,w });// NOOOOOOOOOOOOOOOOOOOOOOOO!!11!1!!!!
	}
	ford_belm(1);
	for (int i = 1; i <= n; i++)
	{
		if (gr[i].dist != inf)
			cout << gr[i].dist << ' ';
		else
			cout << inf << ' ';
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	example();
	return 0;
}
