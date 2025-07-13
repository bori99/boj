#include<iostream>
using namespace std;

unsigned long long func(int n)
{
	unsigned long long temp = 0;

	for (int i = 1; i < n; i++)
	{
		temp += i;
	}
	return temp;
}
int main()
{
	unsigned long long n;
	cin >> n;
	cout << func(n) << "\n" << 2;
}