#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
int d, ans = 0;
vector <int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	while (k--) {
		cin >> s;
		if (s[0] == 'u') {
			cin >> s;
			d = stoi(s);
			for(int i = 0; i < d; i++)
				v.pop_back ();
			ans = v.size () ? v.back () : 0;
		}
		else {
			d = stoi (s);
			ans = (ans + d + n * 10000) % n;
			v.push_back (ans);
		}
	}
	cout << ans << '\n';
}