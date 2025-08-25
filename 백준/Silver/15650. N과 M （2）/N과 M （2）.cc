#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n, m;
vector<int> v;
bool used[10];

void Recur(int size, int pre)
{
	if (size == m)
	{
		for (int i = 0; i < m; i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i] || (pre >= i)) continue;
		v.push_back(i); used[i] = true;
		Recur(size + 1, i);
		v.pop_back(); used[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	Recur(0,0);
}