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


int main() {
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	system("F:");//change on your directory with gen, solve and stupid(C:\ or F:\ or D:\)(don`t use full path, only disk)
	system("g++ solve.cpp -o solve");
	cout << "Solve Ready\n";
	system("g++ gen.cpp -o gen");
	cout << "Gen Ready\n";
	system("g++ stupid.cpp -o stupid");
	cout << "Stupid Ready\n";
	ll score = 1;
	while(true)
	{
		system("gen.exe > input");
		system("stupid.exe < input > output1");
		system("solve.exe < input > output2");
		fstream in0("input", ios_base::in);
		cout << score++ << ") Samlpe:\n";
		string s0;
		while (getline(in0, s0))
			cout << s0 << '\n';
		
		in0.close();
		fstream in1("output1", ios_base::in);
		fstream in2("output2", ios_base::in);
		string s1 = "", s2 = "";
		while (true)
		{
			getline(in1, s1);
			getline(in2, s2);
			if (s1 != s2)// checker
			{
				cout << "\nWA\n";
				in1.close();
				in1.open("output1",ios_base::in);
				cout << "\nANS: \n";
				while (getline(in1, s1))
				{
					cout << s1 << '\n';
				}
				cout << "\nOUT: \n";
				in2.close();
				in2.open("output2", ios_base::in);
				while (getline(in2, s2))
				{
					cout << s2 << '\n';
				}
				goto flag;
			}
			if (in1.eof() && in2.eof())
				break;
		}
		cout << "\nAC\n\n";
	}
flag:
	system("PAUSE");
	return 0;
}
