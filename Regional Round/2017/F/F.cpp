#include <bits/stdc++.h>
using namespace std;

int n,u,v;
vector<int>ar[10005];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>u>>v;
		ar[u].push_back(v);
		ar[v].push_back(u);
	}
}