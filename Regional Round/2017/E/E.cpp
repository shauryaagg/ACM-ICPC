#include <bits/stdc++.h>
using namespace std;

int n, m, v;
unordered_map <string, int> mp;
bool is[505][505] = {{false}}, has[505][505] = {{false}};
string s, ss, d;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    v = 0;
    for (int i = 0; i < n; i++){
        cin >> s >> d >> ss;
        if (mp.find (s) == mp.end ())
            mp[s] = v++;
        if (mp.find (ss) == mp.end ())
            mp[ss] = v++;
        if (!d.compare ("is-a"))
            is[mp[s]][mp[ss]] = 1;
        else
            has[mp[s]][mp[ss]] = 1;
    }
    for (int i = 0; i < v; i++)
        is[i][i] = 1;
    for (int k = 0; k < v; k++){
        for (int i = 0; i < v; i++){
            for (int j = 0; j < v; j++){
                if (is[i][k] && is[k][j])
                    is[i][j] = 1;
                if ((has[i][k] && (is[k][j] || has[k][j])) || (has[k][j] && is[i][k]))
                    has[i][j] = 1;
            }
        }
    } for(int qq = 1; qq <= m; qq++){
        cin >> s >> d >> ss;
        cout << "Query "<< qq << ": ";
        if (!d.compare ("is-a"))
            cout << (is[mp[s]][mp[ss]] ? "true\n" : "false\n");
        else
            cout << (has[mp[s]][mp[ss]] ? "true\n" : "false\n");
    }
}