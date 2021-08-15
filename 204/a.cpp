#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int x,y;
    cin >> x >> y;
    if(x==y) cout << x << endl;
    else if(x!=y) {
        int ans;
        rep(i,3)if(i!=x&&i!=y) ans=i;
        cout << ans << endl;
    }
    return 0;
}