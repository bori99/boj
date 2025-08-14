#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int ans;

int main()
{
	int n;
	cin >> n;

	if (n <= 3) cout << 1;
	else
	{
		int temp = 4;
		if (n <= temp) cout << 2;
		else
		{
			ans = 2;

			for (int i = 5; i <= (2100000000 - 4); i += 2)
			{
				temp += i;
				if (temp > n) break;
				ans++;
			}

			cout << ans;
		}
	}

	
}