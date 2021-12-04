#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n,l,k;
    cin >> n >> l >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ok = 0, ng = l/k+1;
    while(ng-ok > 1) {
        ll leng = 0, count = 0, leng_keep = 0;
        ll m = (ok+ng)/2;
        bool flag1 = false;
        for(int i=0; i<=n; i++) {
            if (i<n) leng = a[i]-leng_keep;
            else leng = l - leng_keep;
            if (leng >= m) {
                leng_keep += leng;
                count ++;
                if (count >= k+1) {
                    flag1 = true;
                }
            }
        }
        if (flag1) ok = m; else ng = m; 
    }
    cout << ok << endl;
    return 0;
}