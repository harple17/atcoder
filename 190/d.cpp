#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    auto is_even = [&](ll m) {
        ll tmp = 2*n/m-m+1;
        if (abs(tmp)%2 == 0) ans++;
    };
    for (ll m1 = 1; m1*m1 <= 2*n; m1++) {
        if (2*n%m1==0) {
            ll m2 = 2*n/m1;
            is_even(m1);
            if (m1 != m2) is_even(m2);
        }
    }
    cout << ans << endl;
    return 0;
}