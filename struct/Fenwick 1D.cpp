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

vector<int> t, a;

int f(int x)//for add
{
	return x & (x + 1);
}
int h(int x)//for out
{
	return x | (x + 1);
}
void add(int i, int x)//add elem
{
	int c = x - a[i]; //delta
	while (i < a.size())
	{
		t[i] += c;
		i = h(i);
	}
}

int prefs(int k)//print sum on sub-section
{
	int res = 0;// score
	while (k >= 0)
	{
		res += t[k];
		k = f(k) - 1;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	//freopen("input.txt", "r", stdin);
	//freopen("input1.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//start array from 1
	return 0;
}
