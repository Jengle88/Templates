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

ll m = ll(1e12) + 39LL;//mod
ll x = 1013;//mnoj


ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= (a % m);
		a %= m;
		n >>= 1;
	}
	return res % m;
}


void hashf(string &s, vector<ll> &a)//string -> array
{
	a[0] = s[0] * x;
	for (int i = 1; i < s.size(); i++)
	{
		a[i] = (a[i - 1] + s[i] * x) % m;
	}
}

ll hashf(string &s)//string -> long long
{
	ll h = s[0] * x;
	for (int i = 1; i < s.size(); i++)
	{
		h += (s[i] * x) % m;
		h %= m;
	}
	return h;
}

void solve()//example (find cyclic shift)
{
	string s;
	cin >> s;
	vector<ll> step(s.size(), 1);
	for (int i = 1; i < s.size(); i++)
	{
		step[i] = (step[i - 1] * x) % m;
	}
	s += s;
	string s1 = s;
	vector<ll> pr(s.size());
	hashf(s, pr);
	int q;
	cin >> q;
flag:
	while (q--)
	{
		cin >> s;
		ll hf = hashf(s);
		if (hf == pr[s.size() - 1])
		{
			cout << "YES\n";
			continue;
		}
		for (int i = 1; i < pr.size() - s.size(); i++)
		{
			if (hf == pr[i + s.size() - 1] - pr[i - 1])
			{
				cout << "YES\n";
				goto flag;
			}
		}
		cout << "NO\n";
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
