#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

unsigned long long n;
unsigned long long ans;
int main()
{
	cin >> n;
	unsigned long long int temp = 0;
	if (n >= 3)
	{
		temp = n * (n - 1) / 2;
		temp = temp * (n - 2) / 3;
	}

	cout << temp << "\n" << 3;
}