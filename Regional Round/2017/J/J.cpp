#include <bits/stdc++.h>
#define ll long long int
#define inf 1000000000000LL
using namespace std;

ll u[10],r[10],t[10];
ll ju[10],jr[10];
ll ans=0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for(int i=0;i<10;i++)
		cin>>ju[i]>>jr[i];
	for(int i=0;i<10;i++)
		cin>>u[i]>>r[i]>>t[i];
	for(int times=0;times<3;++times) {
		for(int i=0;i<10;i++) {
		    if(ans+ju[i]<=t[i]) {
		        ans+=jr[i]+ju[i];
		        continue;
		    }
			ll temp=u[i]-(ans-t[i]+(u[i]+r[i])*500000)%(u[i]+r[i]);
			ans+=max(0LL,temp);
			t[i]+=max(0LL,ju[i]-r[i]-min(0LL,temp));
			ans+=jr[i]+ju[i];
		}
	} cout<<ans-jr[9]<<'\n';
}