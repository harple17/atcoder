#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    ll count = 0;
    for (ll a=2;a<=sqrt(n);a++) {
        ll b_max = log(n)/log(a);
    }
    cout << n-count << endl;
    return 0;
}