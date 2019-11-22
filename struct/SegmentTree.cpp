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
	hoba *l = nullptr, *r = nullptr;
	ll sum = 0, del = 0;
	int lf, rg;
};
vector<ll> a;

hoba* build(int l, int r)
{
	hoba *root = new hoba;
	if (l == r)
	{
		root->lf = root->rg = l;
		root->sum = a[l];
		return root;
	}
	root->lf = l, root->rg = r;
	root->l = build(l, (r + l) / 2);
	root->r = build((r + l) / 2 + 1, r);
	root->sum = root->l->sum + root->r->sum;
	return root;
}

void update_d(hoba *root, int l, int r, int d)
{
	if (root->lf > r || root->rg < l)
		return;
	if (root->lf >= l && root->rg <= r)
	{
		root->del += d * (root->rg - root->lf + 1);
		return;
	}
	update_d(root->l, l, r, d);
	update_d(root->r, l, r, d);
	root->del = root->l->del + root->r->del;
	return;
}

void update_x(hoba *root, int l, int r, int x)//not ready
{
	if (root->lf > r || root->rg < l)
		return;
	if (root->lf >= l && root->rg <= r)
	{	
		root->sum = x * (root->rg - root->lf + 1);
		return;
	}
	update_x(root->l, l, r, x);
	update_x(root->r, l, r, x);
	root->sum = root->r->sum + root->l->sum;
	return;
}

int query(hoba *root, int l, int r)
{
	if (root->lf > r || root->rg < l)
		return 0;
	if (root->lf >= l && root->rg <= r)
	{
		return root->sum + root->del;
	}
	return query(root->l, l, r) + query(root->r, l, r);
}

int main() {
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif*/
	freopen("input.txt", "r", stdin);
	//freopen("input2.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)	cin >> a[i];
	hoba *root = new hoba;
	root = build(0, n - 1);

	return 0;
}
