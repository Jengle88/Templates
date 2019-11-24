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
#include <random>
#include <unordered_map>
//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class T>
using pt = std::pair<T, T>;
using namespace std;

ll sum = 0;
struct treap
{
	treap *l = nullptr, *r = nullptr;
	int y, sz;
	ll x;
	treap(int x) : x(x) { y = rand(); sz = 1; }
	treap() { y = rand() % (int)1e9; sz = 1; }
};
class Treap
{
	void upd(treap *root)// update size node
	{
		if (root)
			root->sz = realsz(root->l) + realsz(root->r) + 1;
	}
	pt<treap*> splitk(treap *root, int k)//split K
	{
		if (root == nullptr)
		{
			return { nullptr,nullptr };
		}
		if (realsz(root->l) < k)
		{
			auto a = splitk(root->r, k - realsz(root->l) - 1);
			root->r = a.first;
			upd(root);
			return { root,a.second };
		}
		else
		{
			auto a = splitk(root->l, k);
			root->l = a.second;
			upd(root);
			return { a.first,root };
		}

	}
	pt<treap*> split(treap *root, int x)//split X
	{
		if (root == nullptr)
		{
			return { nullptr,nullptr };
		}
		if (root->l->x < x)
		{
			auto a = splitk(root->r, x);
			root->r = a.first;
			upd(root);
			return { root,a.second };
		}
		else
		{
			auto a = splitk(root->l, x);
			root->l = a.second;
			upd(root);
			return { a.first,root };
		}

	}
	treap* merge(treap *l, treap *r)// merge
	{
		if (l == nullptr)
		{
			return r;
		}
		else if (r == nullptr)
		{
			return l;
		}
		if (l->y < r->y)
		{
			r->l = merge(l, r->l);
			upd(r);
			return r;

		}
		else
		{
			l->r = merge(l->r, r);
			upd(l);
			return l;

		}
	}
	int realsz(treap *root)// size node
	{
		if (root && !root->l && !root->r)
			return 1;
		else
			return root ? root->sz : 0;
	}
public:
	treap* root = nullptr;
	int size() //count nodes
	{
		return realsz(root);
	}
	void do_dfs(vector<int> &a, treap* t)// treap->vector || print treap || full clear treap
	{
		if (!t->l && !t->r)
		{
			//cout << t->x << ' ' ;
			//a.push_back(t->x);
			//delete t;
		}
		else
		{
			if (t->l) do_dfs(a, t->l);
			//cout << t->x << ' ';
			//a.push_back(t->x);
			if (t->r) do_dfs(a, t->r);
			//delete t;
		}
	}
	void mas_insert(vector<int> &a)// vector->treap
	{
		this->root = new treap;
		for (int i = 0; i < a.size(); i++)
		{
			this->insertk(i, a[i]);
		}
	}
	void edit2(int ind1, int ind2, int ed1, int ed2)// edit 2 neightbors
	{
		auto it1 = find(root, ind1), it2 = find(root, ind2);
		sum -= it1->x * it1->x + it2->x * it2->x;
		it1->x += ed1, it2->x += ed2;
		sum += it1->x * it1->x + it2->x * it2->x;
	}
	void edit1(int ind1, int ed1)// edit 1 neightbor
	{
		auto it = find(root, ind1);
		sum -= it->x * it->x;
		it->x += ed1;
		sum += it->x * it->x;
	}
	void insertk(int ind, int x)// insert K
	{
		ind--;//if start from 1
		auto p = splitk(root, ind);
		treap* n = new treap(x);
		root = merge(merge(p.first, n), p.second);
	}
	treap* find(treap* root, int ind)// find K
	{
		if (ind == realsz(root) - realsz(root->r))
			return root;
		else if (realsz(root->l) >= ind)
			find(root->l, ind);
		else
			find(root->r, ind - realsz(root->l) - 1);
	}
	treap* find(treap* root, int x)// find x
	{
		if (x == root->x)
			return root;
		else if (root->x <= x)
			find(root->l, x);
		else
			find(root->r, x);
	}

	void erase(int ind)// erase K
	{
		ind--;//if start from 1
		auto a = splitk(root, ind + 1);
		auto b = splitk(a.first, realsz(a.first) - 1);
		delete b.second;
		root = merge(b.first, a.second);
	}
};



int main() {
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#else
	#endif*/
	//freopen("input.txt", "r", stdin);
	//freopen("input2.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Treap a;
	return 0;
}
