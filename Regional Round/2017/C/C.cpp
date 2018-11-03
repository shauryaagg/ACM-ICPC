#include <bits/stdc++.h>
using namespace std;

string s, ss = "";
int rv = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for(int i = 0; i < s.length () / 2; i++)
		rv += s[i] - 'A';
	for(int i = 0; i < s.length () / 2; i++) {
		s[i] = (s[i] - 'A' + rv) % 26 + 'A' ;
	}
	rv=0;
	for(int i = s.length () / 2; i < s.length (); i++)
	    rv += s[i] - 'A';
	for(int i = s.length() / 2; i < s.length (); i++) {
		s[i] = (s[i] - 'A' + rv) % 26 + 'A' ;
	}
	for(int i = 0; i < s.length () / 2; i++)
		ss += (s[i] - 2 * 'A' + s[s.length () / 2 + i]) % 26 + 'A' ;
	cout << ss << '\n';
}		
