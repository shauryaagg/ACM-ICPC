#include <bits/stdc++.h>
using namespace std;

int n, ans, ar[105], dp[105][105];
int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        if (n == 2) {
            cout << gcd (ar[0], ar[1]) << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            dp[i][2] = gcd (ar[i], ar[(i + 2) % n]);
            dp[i][1] = 0;
            
        }
        for (int len = 3; len < n - 1; len++) {
            for (int i = 0; i < n; i++) {
                dp[i][len] = INT_MAX;
                for (int k = 1; k < len; k++) {
                    dp[i][len] = min (dp[i][k] + dp[(i + k) % n][len - k], dp[i][len]);
                }
                dp[i][len] += gcd (ar[i], ar[(i + len) % n]);
            }
        }
        for (int i = 0; i < n; i++) {
            int best = 1;
            dp[i][n - 1] = INT_MAX;
            for (int k = 1; k < n - 1; k++) {
                if (dp[i][k] + dp[(i + k) % n][n - 1 - k] < dp[i][n - 1]) {
                    best = i;
                    dp[i][n - 1] = dp[i][k] + dp[(i + k) % n][n - 1 - k];
                }
            }
            dp[i][n - 1] += 2 * min (gcd (ar[i], ar[(i + n - 1) % n]),
                min (gcd(ar[i], ar[(i + best) % n]), gcd (ar[(i + best) % n], ar[(i + n - 1) % n])));
        }
        ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min (ans, dp[i][n - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}

