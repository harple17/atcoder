#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<long> a(n), p(n), x(n);
    rep(i,n) cin >> a[i] >> p[i] >> x[i];
    const long INF = 1000010010;
    long ans = INF;
    rep(i,n) {
        if(x[i]-a[i]>0 && ans>p[i]) ans = p[i]; 
    }
    if (ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}