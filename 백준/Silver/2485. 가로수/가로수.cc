#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int n;
vector<int> v;
int ans;
vector<int> dist;

int gcd(int a, int b)
{
	int n;

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		int temp = v[i + 1] - v[i];
		dist.push_back(temp);
	}

	sort(dist.begin(), dist.end());
	int temp = dist[0];

	for (int i = 1; i < dist.size(); i++)
	{
		temp = gcd(temp, dist[i]);
	}

	for (int i = 0; i < dist.size(); i++)
	{
		ans += (dist[i] / temp) - 1;
	}

	cout << ans;
}