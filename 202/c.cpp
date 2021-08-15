#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1,0), b(n+1), c(n+1);
    for(int i=1;i<=n;i++) {
        int a0; 
        cin >> a0;
        a[a0]++;
    }
    for(int i =1;i<=n;i++) cin >> b[i];
    for(int i =1;i<=n;i++) cin >> c[i];
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        ans += a[b[c[i]]];
    }
    cout << ans << endl;
    return 0;
}