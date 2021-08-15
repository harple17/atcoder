#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<ll, ll>;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<P> C(n);
    rep(i,n) cin >> C[i].first >> C[i].second;
    sort(C.begin(), C.end());
    for(int i=0;i<n;i++) {
        if(C[i].first>k) break;
        k += C[i].second;
    }
    cout << k << endl;
    return 0;
}