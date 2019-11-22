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
	vector<int> a;
	int lf, rg;
};

vector<int> a;

hoba* build(int l, int r)
{
	hoba * root = new hoba;
	if (l == r)
	{
		root->lf = root->rg = l;
		root->a.push_back(a[l]);
		return root;
	}
	root->lf = l; root->rg = r;
	root->l = build(l, (r+l) / 2);
	root->r = build((r+l) / 2 + 1, r);
	root->a.resize(root->l->a.size() + root->r->a.size());
	merge(root->l->a.begin(), root->l->a.end(), root->r->a.begin(), root->r->a.end(), root->a.begin());
	return root;
}

int query(hoba *root, int l, int r, int x)// greater than x
{
	if (l > root->rg || r < root->lf)
		return 0;

	if (l >= root->lf && r <= root->rg)
		return upper_bound(root->a.begin(), root->a.end(), x) - lower_bound(root->a.begin(),root->a.end(),x);

	return query(root->l, l, r, x) + query(root->r, l, r, x);

}

int main() {
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif*/
	freopen("input.txt", "r", stdin);
	//freopen("input1.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	hoba * root = new hoba;
	root = build(0, n-1);

	return 0;
}
