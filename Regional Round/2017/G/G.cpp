#include <bits/stdc++.h>
using namespace std;

int n,m,ar[105],usable[105],dp[105][105];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	usable[1]=m;
	for(int i=2;i<=n;i++)
		usable[i]=usable[i-1]*2/3;
	for(int i=1;i<=n;i++) {
		cin>>ar[i];
	}
	for(int i=n;i>=1;i--) {
		dp[n][i]=min(usable[i],ar[n]);
	}
	for(int i=n-1;i>=1;i--) {
		dp[n-1][i]=max(min(usable[i],ar[n-1])+dp[n][i+1],dp[n][i]);
	}
	for(int i=n-2;i>=1;i--) {
		for(int j=i;j>=1;j--) {
			dp[i][j]=max(min(ar[i],usable[j])+dp[i+1][j+1],max(dp[i+1][j],dp[i+2][1]));
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<dp[i][j] <<" ";
		} cout<<'\n';
	} cout<<'\n';
	cout<<dp[1][1]<<'\n';
}