#include<iostream>
using namespace std;

int t, x_st, y_st;// test case, start point
int x_fi, y_fi;//end point
int n; // planet num

int cx, cy, r; // planet point, radian?
int ans;

bool InterPointSt()
{
	bool start = (x_st - cx) * (x_st - cx) + (y_st - cy) * (y_st - cy) < r * r;
	return start;
}

bool InterPointFi()
{
	bool finish = (x_fi - cx) * (x_fi - cx) + (y_fi - cy) * (y_fi - cy) < r * r;
	return finish;
}

int main()
{
	
	cin >> t;

	while (t--){

		cin >> x_st >> y_st >> x_fi >> y_fi;
		cin >> n;

		for (int i = 0; i < n; i++) {

			cin >> cx >> cy >> r;
			if (InterPointFi() != InterPointSt()) ans++;
		}

		cout << ans << "\n";
		ans = 0;
	}

}