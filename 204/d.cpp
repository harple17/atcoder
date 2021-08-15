#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(),t.end(),greater<int>());
    int ov1=0;
    int ov2=0;
    rep(i,n) {
        if(ov1<=ov2) ov1+=t[i];
        else if(ov1>ov2) ov2+=t[i];
    }
    if(ov1<ov2) cout << ov2 << endl;
    else cout << ov1 << endl;
    return 0;
}