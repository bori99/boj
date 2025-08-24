#include<iostream>
#include <algorithm>
#include<stack>
#include<vector>
#include<string>
using namespace std;
vector<string> v;

string Add(string str1, string str2)
{
	string temp = "";
	while (str2.size() > str1.size()) str1 = "0" + str1;
	while (str1.size() > str2.size()) str2 = "0" + str2;

	int carry = 0;

	for (int i = str1.size() - 1; i >= 0; i--)
	{
		int sum = (str1[i] - '0') + (str2[i] - '0') + carry;
		carry = sum / 10;
		temp += (sum%10)+'0';
	}
	if (carry) temp += carry + '0';

	reverse(temp.begin(), temp.end());
	return temp;
}

int main()
{
	int n; cin >> n;
	v.push_back({ "0" }); v.push_back({ "1" });
	for (int i = 2; i <= n; i++)
	{
		string temp = Add(v[i - 2], v[i - 1]);
		v.push_back({ temp });
	}
	 cout << v[n];
}