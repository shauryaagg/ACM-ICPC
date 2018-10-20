#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map <string, int>mp;
string s;
int main () {
	ios_base::sync_with_stdio (false); cin.tie (0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s] = i + 1;
	}

}