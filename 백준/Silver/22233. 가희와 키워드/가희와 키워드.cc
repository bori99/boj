#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int N, M;
unordered_set<string> keyword;

vector<string> Parsing_function(string str)
{
	size_t start = 0;
	size_t end = str.find(',');
	vector<string> Ans;

	while (end != string::npos)
	{
		Ans.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(',', start);
	}

	Ans.push_back(str.substr(start));
	return Ans;
}

void Input()
{
	string word;
	cin >> N >> M;
	while (N--)
	{
		cin >> word;
		keyword.insert(word);
	}
	while (M--)
	{
		string before_parsing;
		cin >> before_parsing;
		vector<string> after_parsing = Parsing_function(before_parsing);

		for (int i = 0; i < after_parsing.size(); i++)
		{
			keyword.erase(after_parsing[i]);
		}
		cout << keyword.size() << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	Input();
}