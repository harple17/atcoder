#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll>::iterator e = remove(a.begin(), a.end(), x);
    a.erase(e, a.end());

    vector<ll>::iterator j = a.begin();
    while(j!=a.end()) {
        cout << *j;
        j++;
        cout << " ";
    }
    cout << endl;
    return 0;
}