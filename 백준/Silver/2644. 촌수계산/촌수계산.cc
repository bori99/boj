#include<iostream>
#include<stack>
using namespace std;

stack<int> st;
int n, t1, t2, m;
int temp1, temp2;
bool used[101];
bool graph[101][101];
int ans;

void DSearch()
{
	if (st.empty() == true)return;
	if (st.top() == t2) return;

	int temp = st.top();
	st.pop();

	for (int i = 1; i <= n; i++)
	{
		if (used[i] == false && graph[temp][i] == true)
		{
			ans++;
			st.push(i); 
			used[i] = true; 
			DSearch();
			if (st.empty() != true)
			{
				if (st.top() == t2) break;
			}
			ans--;
		}
	}
}

int main()
{
	cin >> n >> t1 >> t2 >> m;
	

	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		graph[temp1][temp2] = true;
		graph[temp2][temp1] = true;
	}

	st.push(t1);
	used[t1] = true;
	DSearch();

	if (st.empty()) cout << -1;
	else cout << ans;
}