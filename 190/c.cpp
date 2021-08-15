#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    rep(i,k) cin >> c[i] >> d[i];    

    int ans = 0;
    rep(i,1<<k) {
        vector<int> dish(n+1);
        rep(j,k) {
            if ((i>>j)&1) dish[c[j]]++;
            else dish[d[j]]++;
        }
        int now = 0;
        rep(j,m) {
            if (!dish[a[j]]) continue;
            if (!dish[b[j]]) continue;
            now++;
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}