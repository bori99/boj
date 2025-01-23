#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
/* 자료구조를 선택하는 문제란 것은 알았으나 map으로 접근해서 시간초과. set으로 접근해도 시간초과였을 것임. set과 map은 정렬을 하는 것을 가정한 red black tree로 구현됨
그래서 삽입, 발견, 삭제등이 O(logn)에 이루어져서 데이터가 빈번히 삽입, 삭제될시 효율적이지 못해 시간초과가 발생했던 것임. 이럴떄는 정렬을 하지 않고 Hash table로 내부 
구현된 Unordered set과 map을 이용해야됬음. hash function이 이상적이라면, 삽입, 삭제가 O(1)에 이루어짐. */
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
