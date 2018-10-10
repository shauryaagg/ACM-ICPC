#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0;
char arr[105][105];
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,-1,1,1,-1};
bool vis[105][105]={false};
void dfs(int i, int j) {
	if(vis[i][j])
		return;
	vis[i][j]=1;
	for(int k=0;k<8;k++) {
		if(arr[i+dx[k]][j+dy[k]]=='#')
			dfs(i+dx[k],j+dy[k]);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>arr[i][j];
			vis[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++) {
	    for(int j=1;j<=m;j++) {
	        if(arr[i][j]=='.')
	            continue;
	        if(!vis[i][j])
	        	++ans;
	        dfs(i,j);
	    }
	} cout<<ans<<'\n';
}