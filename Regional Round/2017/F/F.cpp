#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, u, v, dis[10001];
ll n1, n2, x, sum;
bool vis[10001];
vector <int> tss, ar[10001];

int dfs (int node) {
    if (vis[node])
        return 0;
    vis[node] = 1;
    int c = 1;
    for (int i = 0; i < ar[node].size (); i++) {
        c += dfs (ar[node][i]);
    }
    return dis[node] = c;
}
void init () {
    tss.clear ();
    for (int i = 0; i <= n; i++)
        vis[i] = 0;
}
int main() {
    ios_base::sync_with_stdio (false); cin.tie (0);
    cin >> n;
    n1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        ar[u].push_back (v);
        ar[v].push_back (u);
    }
    dfs (0);
    for (int i = 0; i <= n; i++) {
        sum = 0;
        for (int j = 0; j < ar[i].size (); j++) {
            if (dis[ar[i][j]] < dis[i])
                x = dis[ar[i][j]];
            else
                x = n - dis[i] + 1;
            sum += x;
            tss.push_back (x);
        }
        x = 0;
        for (int j = 0; j < tss.size (); j++) {
            x += (sum - tss[j]) * tss[j];
        }
        if (x > n1) {
            n1 = x;
            if (tss.size () <= 1) {
                n2 = 0;
            }
            else {
                sort (tss.begin (), tss.end ());
                tss[tss.size () - 2] += tss.back ();
                x = 0;
                for (int j = 0; j < tss.size () - 1; j++) {
                    x += tss[j] * (sum - tss[j]);
                }
                n2 = x;
            }
            
        }
        tss.clear ();
    }

    cout << n1 / 2 << ' ' << n2 / 2 << '\n';
    return 0;
}