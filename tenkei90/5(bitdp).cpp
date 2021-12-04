#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,b,k;
    cin >> n >> b >> k;
    vector<int> c(k); 
    rep(i,k) cin >> c[i];
    const int MOD = 1e9+7;
    vector<vector<int>> dp(n+1, vector<int>(b, 0));
    rep(i, k) dp[1][c[i]%b]++;
    for (int i=1; i<n; i++) {
        for (int j=0; j<b; j++) {
            for (int l=0; l<k; l++) {
                int next = (10*j + c[l]) % b; //次の桁での余り
                dp[i+1][next] += dp[i][j];
                dp[i+1][next] %= MOD;
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}